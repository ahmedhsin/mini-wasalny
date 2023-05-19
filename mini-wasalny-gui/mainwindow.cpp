
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lib/drawGraph.cpp"
#include "lib/Graph.h"


struct color{
    double x, y, z;
    sf::Color getColor(){
        return  sf::Color(x,y,z);
    }
};
struct theme{
    color NodeColor, VisitedColor, bgColor, textColor,lineColor;
};
Graph graph(false);
Graph temp(false);
unordered_map<string, unordered_set<Edge, EdgeHash>> *adj = graph.getAdjacencyList();

vector<theme> themes = {{{0,91,150},{179,205,224},{1,27,73},{201, 231, 253},{100,151,177}},
                        {{240, 108, 155}, {182, 207, 246}, {42, 47, 59}, {235, 235, 235}, {140, 199, 242}} ,
                        {{99, 114, 133}, {114, 137, 218}, {30, 33, 36}, {182, 197, 253}, {182, 197, 253}}};
int currenTheme = 0;
sf::Color NodeColor = sf::Color(themes[currenTheme].NodeColor.getColor());
sf::Color VisitedColor = sf::Color(themes[currenTheme].VisitedColor.getColor());
sf::Color bgColor = sf::Color(themes[currenTheme].bgColor.getColor());
sf::Color textColor = sf::Color(themes[currenTheme].textColor.getColor());
sf::Color lineColor = sf::Color(themes[currenTheme].lineColor.getColor());

float Speed = 0.5f;
bool GraphStyle = false;
string arow = " - ";

vector<string> emptyVector;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

    , ui(new Ui::MainWindow)

{

    ui->setupUi(this);
    connect(ui->Current_Graph, &QPushButton::clicked, [this]() {
        if (graph.IsEmpty()){
            //output no graph
            ui->mainStack->setCurrentIndex(0);
        }else{
            ui->mainStack->setCurrentIndex(2);
        }


    });

    connect(ui->New_Graph, &QPushButton::clicked, [this]() {
        ui->mainStack->setCurrentIndex(0);
    });
    connect(ui->Dir_Graph, &QPushButton::clicked, [this]() {
        ui->mainStack->setCurrentIndex(2);
        graph.DelGraph();
        Graph g(true);
        graph = g;

    });
    connect(ui->UnDir_Graph, &QPushButton::clicked, [this]() {
        ui->mainStack->setCurrentIndex(2);
        graph.DelGraph();
        Graph g(false);
        graph = g;

    });
    connect(ui->Back, &QPushButton::clicked, [this]() {
        ui->mainStack->setCurrentIndex(0);
        ui->test_->setText("");
        ui->log->clear();
        ui->Console->clear();
    });
    connect(ui->exit, &QPushButton::clicked, [this]() {
        this->close();
    });
    adj = graph.getAdjacencyList();
    ui->log->hide();
    ui->Console->hide();
    ui->theme->setCurrentRow(currenTheme);
    ui->Console_btn->hide();
    connect(ui->town, &QPushButton::clicked, [this]() {
        ui->Qstack->setCurrentIndex(0);
    });
    connect(ui->traversal, &QPushButton::clicked, [this]() {
        ui->Qstack->setCurrentIndex(1);
    });
    connect(ui->edge, &QPushButton::clicked, [this]() {
        ui->Qstack->setCurrentIndex(2);
    });
    connect(ui->shortpath, &QPushButton::clicked, [this]() {
        ui->Qstack->setCurrentIndex(3);
    });
    connect(ui->Console_btn, &QPushButton::clicked, [this]() {
        if (ui->Console_btn->text() == "Console"){
            ui->Console_btn->setText("Hide");
            ui->Console->show();
        }else{
            ui->Console_btn->setText("Console");
            ui->Console->hide();
        }
    });
    connect(ui->graph_text, &QRadioButton::clicked, [this]() {
        if (ui->Console_btn->text() == "Console"){
            ui->Console_btn->click();
        }
    });
    connect(ui->graph_gra, &QRadioButton::clicked, [this]() {
        if (ui->Console_btn->text() == "Hide"){
            ui->Console_btn->click();
        }
    });
    connect(ui->displaygraph, &QPushButton::clicked, [this]() {
        if (ui->graph_text->isChecked()){
            ui->Console->clear();
            for (auto& city : *adj){
                int i = 1;
                string src = "Source : " + city.first;
                ui->Console->addItem(QString::fromStdString(src));
                ui->Console->addItem("neighbours : ");
                string ans = "";
                for (auto& neb : city.second){
                    if (!neb.valid)
                        continue;
                    if (i%2 == 0)
                        ans += "\n";
                    ans += "{" + neb.dest + ", " + to_string(neb.dist) + "} ";
                    i++;
                }
                ui->Console->addItem(QString::fromStdString(ans));
            }
        }else if(ui->graph_gra->isChecked())
            RUN(*adj, emptyVector, Speed, NodeColor, VisitedColor, bgColor, textColor, lineColor, GraphStyle);
    });
    connect(ui->addTown, &QPushButton::clicked, [this]() {
        string city = ui->text_City->toPlainText().toStdString();
        bool state = graph.AddVertex(city);
        if (state){
            ui->test_->setText("OK");
            string log = "Town '" + city + "' (+)";
            ui->log->addItem(QString::fromStdString(log));
        }
        else
            ui->test_->setText("Error");
    });
    connect(ui->deleteTown, &QPushButton::clicked, [this]() {
        string city = ui->text_City->toPlainText().toStdString();
        bool state = graph.DelVertex(city);
        if (state){
            ui->test_->setText("OK");
            string log = "Town '" + city + "' (-)";
            ui->log->addItem(QString::fromStdString(log));
        }else
            ui->test_->setText("Error");
    });

    connect(ui->AddEdge, &QPushButton::clicked, [this]() {
        string src = ui->fCityEdge->toPlainText().toStdString();
        string dest = ui->sCityEdge->toPlainText().toStdString();
        double dist = ui->dEdge->toPlainText().toDouble();
        bool state = graph.AddEdge(src, dest, dist);
        if (state){
            ui->test_->setText("OK");
            string log = "Route '" + src + arow + dest +"' ("+ to_string(dist) +") (+)";
            ui->log->addItem(QString::fromStdString(log));
        }else
            ui->test_->setText("Error");
    });

    connect(ui->DeleteEdge, &QPushButton::clicked, [this]() {
        string src = ui->fCityEdge->toPlainText().toStdString();
        string dest = ui->sCityEdge->toPlainText().toStdString();
        double dist = ui->dEdge->toPlainText().toDouble();
        bool state = graph.DelEdge(src, dest, dist);
        if (state){
            ui->test_->setText("OK");
            string log = "Route '" + src + arow + dest +"' ("+ to_string(dist) +") (-)";
            ui->log->addItem(QString::fromStdString(log));
        }else
            ui->test_->setText("Error");
    });
    connect(ui->GSpeed, &QDoubleSpinBox::valueChanged, [this]() {
        Speed = ui->GSpeed->text().toDouble();
    });
    connect(ui->startShort, &QPushButton::clicked, [this]() {
        string src = ui->firstShort->toPlainText().toStdString();
        string dest = ui->secondShort->toPlainText().toStdString();
        pair<vector<string>, double> answer;
        if (ui->radio_Dijkstra->isChecked())
            answer = graph.Dijkstra(src, dest);
        else
            answer = graph.BellmanFord(src, dest);
        bool state = true;
        if (answer.first.size() == 0)
            state = false;
        if (state){
            ui->mindistance->setText(QString::number(answer.second));
            if (ui->graph_text->isChecked()){
                ui->Console->clear();
                for (auto city : answer.first){
                    ui->Console->addItem(QString::fromStdString(city));
                }
            }else if(ui->graph_gra->isChecked())
                RUN(*adj, answer.first, Speed, NodeColor, VisitedColor, bgColor, textColor, lineColor, GraphStyle);            ui->test_->setText("OK");
        }
        else
            ui->test_->setText("Error");
    });
    connect(ui->startBFS, &QPushButton::clicked, [this]() {
        string src = ui->textCityTraversal->toPlainText().toStdString();
        vector<string> answer;
        answer = graph.BFS(src);
        bool state = true;
        if (answer.size() == 0)
            state = false;
        if (state){
            ui->test_->setText("OK");
            if (ui->graph_text->isChecked()){
                ui->Console->clear();
                for (auto city : answer){
                    ui->Console->addItem(QString::fromStdString(city));
                }
            }else if(ui->graph_gra->isChecked())
                RUN(*adj, answer, Speed, NodeColor, VisitedColor, bgColor, textColor, lineColor, GraphStyle);
        }
        else
            ui->test_->setText("Error");
    });

    connect(ui->startDFS, &QPushButton::clicked, [this]() {
        string src = ui->textCityTraversal->toPlainText().toStdString();
        vector<string> answer;
        answer = graph.DFS(src);
        bool state = true;
        if (answer.size() == 0)
            state = false;
        if (state){
            ui->test_->setText("OK");
            if (ui->graph_text->isChecked()){
                ui->Console->clear();
                for (auto city : answer){
                    ui->Console->addItem(QString::fromStdString(city));
                }
            }else if(ui->graph_gra->isChecked())
                RUN(*adj, answer, Speed, NodeColor, VisitedColor, bgColor, textColor, lineColor, GraphStyle);
        }
        else
            ui->test_->setText("Error");
    });
    connect(ui->sHistory, &QPushButton::clicked, [this]() {
        if (ui->sHistory->text() == "Show History"){
            ui->log->show();
            ui->sHistory->setText("Hide History");
        }else{
            ui->log->hide();
            ui->sHistory->setText("Show History");
        }
    });
    connect(ui->undo, &QPushButton::clicked, [this]() {
        if (ui->log->count() > 0){
            delete ui->log->item(ui->log->count()-1);
            graph.Undo();
        }
    });
    connect(ui->theme, &QListWidget::currentRowChanged, [this]() {
        currenTheme = ui->theme->currentRow();
        NodeColor = sf::Color(themes[currenTheme].NodeColor.getColor());
        VisitedColor = sf::Color(themes[currenTheme].VisitedColor.getColor());
        bgColor = sf::Color(themes[currenTheme].bgColor.getColor());
        textColor = sf::Color(themes[currenTheme].textColor.getColor());
        lineColor = sf::Color(themes[currenTheme].lineColor.getColor());
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}


