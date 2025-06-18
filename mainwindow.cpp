#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);

    ui->tabWidget->setCurrentIndex(0);

    connect(ui->tutorialButton, &QPushButton::clicked, this, &MainWindow::on_tutorialButton_clicked);

    gateLogic["AND"] = [](int a, int b) { return a & b; };
    gateLogic["OR"] = [](int a, int b) { return a | b; };
    gateLogic["NAND"] = [](int a, int b) { return !(a & b); };
    gateLogic["NOR"] = [](int a, int b) { return !(a | b); };
    gateLogic["XOR"] = [](int a, int b) { return a ^ b; };

    currentGate = "AND";

    connect(ui->input1Button, &QPushButton::clicked, this, &MainWindow::toggleTInputs);
    connect(ui->input2Button, &QPushButton::clicked, this, &MainWindow::toggleTInputs);
    connect(ui->notGateInputButton, &QPushButton::clicked, this, &MainWindow::toggleTInputs);

    currentLevel=1;

    connect(ui->levelsButton, &QPushButton::clicked, this, &MainWindow::on_levelsButton_clicked);
    connect(ui->tutorialBackButton, &QPushButton::clicked, this, &MainWindow::mainBackButton_clicked);
    connect(ui->levelsBackButton, &QPushButton::clicked, this, &MainWindow::mainBackButton_clicked);

    connect(ui->levelButton1, &QPushButton::clicked, this, &MainWindow::openLevel1);
    connect(ui->levelButton2, &QPushButton::clicked, this, &MainWindow::openLevel2);
    connect(ui->levelButton3, &QPushButton::clicked, this, &MainWindow::openLevel3);
    connect(ui->levelButton4, &QPushButton::clicked, this, &MainWindow::openLevel4);
    connect(ui->levelButton5, &QPushButton::clicked, this, &MainWindow::openLevel5);
    connect(ui->levelButton6, &QPushButton::clicked, this, &MainWindow::openLevel6);

    connect(ui->level1BackButton, &QPushButton::clicked, this, &MainWindow::goToLevelsPage);
    connect(ui->level2BackButton, &QPushButton::clicked, this, &MainWindow::goToLevelsPage);
    connect(ui->level3BackButton, &QPushButton::clicked, this, &MainWindow::goToLevelsPage);
    connect(ui->level4BackButton, &QPushButton::clicked, this, &MainWindow::goToLevelsPage);
    connect(ui->level5BackButton, &QPushButton::clicked, this, &MainWindow::goToLevelsPage);
    connect(ui->level6BackButton, &QPushButton::clicked, this, &MainWindow::goToLevelsPage);

    connect(ui->inputA1, &QPushButton::clicked, this, &::MainWindow::toggleInput);
    connect(ui->inputB1, &QPushButton::clicked, this, &MainWindow::toggleInput);
    connect(ui->inputC1, &QPushButton::clicked, this, &MainWindow::toggleInput);

    connect(ui->inputA2, &QPushButton::clicked, this, &MainWindow::toggleInput);
    connect(ui->inputB2, &QPushButton::clicked, this, &MainWindow::toggleInput);

    connect(ui->inputA3, &QPushButton::clicked, this, &MainWindow::toggleInput);
    connect(ui->inputB3, &QPushButton::clicked, this, &MainWindow::toggleInput);
    connect(ui->inputC3, &QPushButton::clicked, this, &MainWindow::toggleInput);

    connect(ui->inputA4, &QPushButton::clicked, this, &MainWindow::toggleInput);
    connect(ui->inputB4, &QPushButton::clicked, this, &MainWindow::toggleInput);
    connect(ui->inputC4, &QPushButton::clicked, this, &MainWindow::toggleInput);
    connect(ui->inputD4, &QPushButton::clicked, this, &MainWindow::toggleInput);

    connect(ui->inputA5, &QPushButton::clicked, this, &MainWindow::toggleInput);
    connect(ui->inputB5, &QPushButton::clicked, this, &MainWindow::toggleInput);
    connect(ui->inputC5, &QPushButton::clicked, this, &MainWindow::toggleInput);
    connect(ui->inputD5, &QPushButton::clicked, this, &MainWindow::toggleInput);

    connect(ui->inputA6, &QPushButton::clicked, this, &MainWindow::toggleInput);
    connect(ui->inputB6, &QPushButton::clicked, this, &MainWindow::toggleInput);
    connect(ui->inputC6, &QPushButton::clicked, this, &MainWindow::toggleInput);
    connect(ui->inputD6, &QPushButton::clicked, this, &MainWindow::toggleInput);
    connect(ui->inputE6, &QPushButton::clicked, this, &MainWindow::toggleInput);

    connect(ui->submitLevel1Button, &QPushButton::clicked, this, &MainWindow::submitLevel);
    connect(ui->submitLevel2Button, &QPushButton::clicked, this, &MainWindow::submitLevel);
    connect(ui->submitLevel3Button, &QPushButton::clicked, this, &MainWindow::submitLevel);
    connect(ui->submitLevel4Button, &QPushButton::clicked, this, &MainWindow::submitLevel);
    connect(ui->submitLevel5Button, &QPushButton::clicked, this, &MainWindow::submitLevel);
    connect(ui->submitLevel6Button, &QPushButton::clicked, this, &MainWindow::submitLevel);

    connect(ui->Gate1, &QComboBox::currentIndexChanged, this, &MainWindow::updateGateImage);
    connect(ui->Gate2, &QComboBox::currentIndexChanged, this, &MainWindow::updateGateImage);
    connect(ui->Gate3, &QComboBox::currentIndexChanged, this, &MainWindow::updateGateImage);
    connect(ui->Gate4, &QComboBox::currentIndexChanged, this, &MainWindow::updateGateImage);
    connect(ui->Gate5, &QComboBox::currentIndexChanged, this, &MainWindow::updateGateImage);
    connect(ui->Gate6, &QComboBox::currentIndexChanged, this, &MainWindow::updateGateImage);
    connect(ui->Gate7, &QComboBox::currentIndexChanged, this, &MainWindow::updateGateImage);
    connect(ui->Gate8, &QComboBox::currentIndexChanged, this, &MainWindow::updateGateImage);
    connect(ui->Gate9, &QComboBox::currentIndexChanged, this, &MainWindow::updateGateImage);
    connect(ui->Gate10, &QComboBox::currentIndexChanged, this, &MainWindow::updateGateImage);
    connect(ui->Gate11, &QComboBox::currentIndexChanged, this, &MainWindow::updateGateImage);
    connect(ui->Gate12, &QComboBox::currentIndexChanged, this, &MainWindow::updateGateImage);
    connect(ui->Gate13, &QComboBox::currentIndexChanged, this, &MainWindow::updateGateImage);
    connect(ui->Gate14, &QComboBox::currentIndexChanged, this, &MainWindow::updateGateImage);
    connect(ui->Gate15, &QComboBox::currentIndexChanged, this, &MainWindow::updateGateImage);
    connect(ui->Gate16, &QComboBox::currentIndexChanged, this, &MainWindow::updateGateImage);
    connect(ui->Gate17, &QComboBox::currentIndexChanged, this, &MainWindow::updateGateImage);
    connect(ui->Gate18, &QComboBox::currentIndexChanged, this, &MainWindow::updateGateImage);
    connect(ui->Gate19, &QComboBox::currentIndexChanged, this, &MainWindow::updateGateImage);
    connect(ui->Gate20, &QComboBox::currentIndexChanged, this, &MainWindow::updateGateImage);
    connect(ui->Gate21, &QComboBox::currentIndexChanged, this, &MainWindow::updateGateImage);
    connect(ui->Gate22, &QComboBox::currentIndexChanged, this, &MainWindow::updateGateImage);

    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onTabChanged);

    updateOutput();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tutorialButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->input1Button->hide();
    ui->input2Button->hide();
    ui->outputCircle->hide();
}

void MainWindow::toggleTInputs()
{
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    if (senderButton) {
        if (senderButton->text() == "0")
        {
            senderButton->setText("1");
            senderButton->setStyleSheet("background-color: #2ECC71; color: #FFFFFF; font-size: 12px; font-weight: bold; border: 2px solid #27AE60; border-radius: 10px; padding: 8px 16px;");
        }
        else
        {
            senderButton->setText("0");
            senderButton->setStyleSheet("background-color: #E74C3C; color: #FFFFFF; font-size: 12px; font-weight: bold; border: 2px solid #C0392B; border-radius: 10px; padding: 8px 16px;");
        }
        updateOutput();
    }
}


void MainWindow::updateOutput()
{
    if (currentGate == "NOT")
    {
        int input = ui->notGateInputButton->text().toInt();
        int output = !input;

        if (output == 1)
        {
            ui->notGateOutputLabel->setStyleSheet("background-color: rgb(247,255,0); border-radius: 25px;");
        }
        else
        {
            ui->notGateOutputLabel->setStyleSheet("background-color: rgb(128, 128, 128); border-radius: 25px;");
        }
    }
    else
    {
        int input1 = ui->input1Button->text().toInt();
        int input2 = ui->input2Button->text().toInt();

        int output = gateLogic[currentGate](input1, input2);

        if (output == 1)
        {
            ui->outputCircle->setStyleSheet("background-color: rgb(247,255,0); border-radius: 25px;");
        }
        else
        {
            ui->outputCircle->setStyleSheet("background-color: rgb(128, 128, 128); border-radius: 25px;");
        }
    }
}


void MainWindow::onTabChanged(int index)
{
    ui->input1Button->setText("0");
    ui->input1Button->setStyleSheet("background-color: rgb(9, 40, 93); color: white; font: bold 12pt");


    ui->input2Button->setText("0");
    ui->input2Button->setStyleSheet("background-color: rgb(9, 40, 93); color: white; font: bold 12pt");

    if (index == 0)
    {
        ui->input1Button->hide();
        ui->input2Button->hide();
        ui->outputCircle->hide();
    }
    else if (index == 3)
    {
        ui->input1Button->hide();
        ui->input2Button->hide();
        ui->outputCircle->hide();

        ui->notGateInputButton->show();
        ui->notGateOutputLabel->show();
    }
    else
    {
        ui->input1Button->show();
        ui->input2Button->show();
        ui->outputCircle->show();

        ui->notGateInputButton->hide();
        ui->notGateOutputLabel->hide();
    }

    switch (index)
    {
    case 1: currentGate = "AND"; break;
    case 2: currentGate = "OR"; break;
    case 3: currentGate = "NOT"; break;
    case 4: currentGate = "NAND"; break;
    case 5: currentGate = "NOR"; break;
    case 6: currentGate = "XOR"; break;
    default: currentGate = "AND"; break;
    }

    updateOutput();
}

void MainWindow::on_levelsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::mainBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::openLevel1() {
    currentLevel=1;
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(ui->level1Page));
}

void MainWindow::openLevel2() {
    currentLevel=2;
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(ui->level2Page));
}

void MainWindow::openLevel3() {
    currentLevel=3;
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(ui->level3Page));
}

void MainWindow::openLevel4() {
    currentLevel=4;
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(ui->level4Page));
}

void MainWindow::openLevel5() {
    currentLevel=5;
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(ui->level5Page));
}

void MainWindow::openLevel6() {
    currentLevel=6;
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(ui->level6Page));
}


void MainWindow::goToLevelsPage()
{
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(ui->levelsPage));
}

void MainWindow::toggleInput()
{
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    if (senderButton) {
        if (senderButton->text() == "0")
        {
            senderButton->setText("1");
            senderButton->setStyleSheet("background-color: #2ECC71; color: #FFFFFF; font-size: 12px; font-weight: bold; border: 2px solid #27AE60; border-radius: 10px; padding: 8px 16px;");
        }
        else
        {
            senderButton->setText("0");
            senderButton->setStyleSheet("background-color: #E74C3C; color: #FFFFFF; font-size: 12px; font-weight: bold; border: 2px solid #C0392B; border-radius: 10px; padding: 8px 16px;");
        }

        switch (currentLevel) {
        case 1: updateLevel1Output(); break;
        case 2: updateLevel2Output(); break;
        case 3: updateLevel3Output(); break;
        case 4: updateLevel4Output(); break;
        case 5: updateLevel5Output(); break;
        case 6: updateLevel6Output(); break;
        default: break;
        }
    }
}


int MainWindow::evaluateGate(const QString& gate, int input1, int input2)
{
    if (gate == "AND")
        return input1 & input2;
    else if (gate == "OR")
        return input1 | input2;
    else if (gate == "XOR")
        return input1 ^ input2;
    else if (gate == "NAND")
        return !(input1 & input2);
    else if (gate == "NOR")
        return !(input1 | input2);
    else
        return 0; // Default to 0 for invalid gates
}

int MainWindow::evaluateNotGate(const QString& gate, int input)
{
    if (gate == "NOT")
        return !input;
    else
        return input;
}

void MainWindow::updateLevel1Output()
{
    int A = ui->inputA1->text().toInt();
    int B = ui->inputB1->text().toInt();
    int C = ui->inputC1->text().toInt();

    QString gate1 = ui->Gate1->currentText();
    QString gate2 = ui->Gate2->currentText();

    int intermediate1_1 = evaluateGate(gate1, A, B);
    int finalOutput1 = evaluateGate(gate2, intermediate1_1, C);

    ui->CurrentOutput1->setText(QString::number(finalOutput1));

    if (finalOutput1){
        ui->outputCircle1->setStyleSheet("background-color: rgb(247,255,0); border-radius: 25px;");
    }
    else{
        ui->outputCircle1->setStyleSheet("background-color: rgb(128, 128, 128); border-radius: 25px;");
    }
}

void MainWindow::updateGateImage()
{
    int index=-1;

    QComboBox *senderComboBox = qobject_cast<QComboBox *>(sender());
    if (!senderComboBox) return;

    QString comboBoxName = senderComboBox->objectName();
    QString labelName = comboBoxName + "Image";

    QLabel *associatedLabel = findChild<QLabel *>(labelName);
    if (!associatedLabel) return;

    index = senderComboBox->currentIndex();

    QIcon selectedIcon = senderComboBox->itemIcon(index);

    QPixmap pixmap = selectedIcon.pixmap(associatedLabel->size());
    associatedLabel->setPixmap(pixmap);

    associatedLabel->repaint();

    switch (currentLevel) {
    case 1: updateLevel1Output(); break;
    case 2: updateLevel2Output(); break;
    case 3: updateLevel3Output(); break;
    case 4: updateLevel4Output(); break;
    case 5: updateLevel5Output(); break;
    case 6: updateLevel6Output(); break;
    default: break;
    }
}


void MainWindow::updateLevel2Output()
{
    int A = ui->inputA2->text().toInt();
    int B = ui->inputB2->text().toInt();

    QString gate1 = ui->Gate3->currentText();
    QString gate2 = ui->Gate4->currentText();

    bool error = false;
    QString errorMessage = "Recheck the number of inputs!";

    if (gate1 == "NOT") {
        error = true;
    }

    if (gate2 != "NOT") {
        error = true;
    }

    if (error) {
        ui->level2FeedbackLabel->setText(errorMessage);
        ui->level2FeedbackLabel->setStyleSheet("font-size: 14px; font-weight: bold; color: #FFFFFF; background-color:   #A93226;  border: 2px solid transparent; padding: 10px; border-radius: 5px; text-align: center; vertical-align: middle;");
        ui->CurrentOutput2->setText("X");
        return;
    }

    int intermediate = evaluateGate(gate1, A, B);
    int finalOutput2 = evaluateNotGate(gate2, intermediate);

    ui->CurrentOutput2->setText(QString::number(finalOutput2));
    ui->level2FeedbackLabel->clear();

    if (finalOutput2){
        ui->outputCircle2->setStyleSheet("background-color: rgb(247,255,0); border-radius: 25px;");
    }
    else{
        ui->outputCircle2->setStyleSheet("background-color: rgb(128, 128, 128); border-radius: 25px;");
    }
}


void MainWindow::updateLevel3Output()
{
    int A = ui->inputA3->text().toInt();
    int B = ui->inputB3->text().toInt();
    int C = ui->inputC3->text().toInt();

    QString gate1 = ui->Gate5->currentText();
    QString gate2 = ui->Gate6->currentText();
    QString gate3 = ui->Gate7->currentText();
    QString gate4 = ui->Gate8->currentText();

    bool error = false;
    QString errorMessage = "Recheck the number of inputs!";

    if (gate3 != "NOT") {
        error = true;
    }

    if (error) {
        ui->level3FeedbackLabel->setText(errorMessage);
        ui->level3FeedbackLabel->setStyleSheet("font-size: 14px; font-weight: bold; color: #FFFFFF; background-color:   #A93226;  border: 2px solid transparent; padding: 10px; border-radius: 5px; text-align: center; vertical-align: middle;");
        ui->CurrentOutput3->setText("X");
        return;
    }

    int intermediate1_3 = evaluateGate(gate1, A, B);
    int intermediate2_3 = evaluateGate(gate2, A, C);
    int intermediate3_3 = evaluateNotGate(gate3, intermediate1_3);
    int finalOutput3 = evaluateGate(gate4, intermediate3_3, intermediate2_3);

    ui->CurrentOutput3->setText(QString::number(finalOutput3));
    ui->level3FeedbackLabel->clear();

    if (finalOutput3){
        ui->outputCircle3->setStyleSheet("background-color: rgb(247,255,0); border-radius: 25px;");
    }
    else{
        ui->outputCircle3->setStyleSheet("background-color: rgb(128, 128, 128); border-radius: 25px;");
    }
}

void MainWindow::updateLevel4Output()
{
    int A = ui->inputA4->text().toInt();
    int B = ui->inputB4->text().toInt();
    int C = ui->inputC4->text().toInt();
    int D = ui->inputD4->text().toInt();

    QString gate1 = ui->Gate9->currentText();
    QString gate2 = ui->Gate10->currentText();
    QString gate3 = ui->Gate11->currentText();
    QString gate4 = ui->Gate12->currentText();

    bool error = false;
    QString errorMessage = "Recheck the number of inputs!";

    if (gate2 != "NOT") {
        error = true;
    }

    if (error) {
        ui->level4FeedbackLabel->setText(errorMessage);
        ui->level4FeedbackLabel->setStyleSheet("font-size: 14px; font-weight: bold; color: #FFFFFF; background-color:   #A93226;  border: 2px solid transparent; padding: 10px; border-radius: 5px; text-align: center; vertical-align: middle;");
        ui->CurrentOutput4->setText("X");
        return;
    }

    int intermediate1_4 = evaluateGate(gate1, B, C);
    int intermediate2_4 = evaluateGate(gate3, A, intermediate1_4);
    int intermediate3_4 = evaluateNotGate(gate2, D);
    int finalOutput4 = evaluateGate(gate4, intermediate2_4, intermediate3_4);

    ui->CurrentOutput4->setText(QString::number(finalOutput4));
    ui->level4FeedbackLabel->clear();

    if (finalOutput4){
        ui->outputCircle4->setStyleSheet("background-color: rgb(247,255,0); border-radius: 25px;");
    }
    else{
        ui->outputCircle4->setStyleSheet("background-color: rgb(128, 128, 128); border-radius: 25px;");
    }
}

void MainWindow::updateLevel5Output()
{
    int A = ui->inputA5->text().toInt();
    int B = ui->inputB5->text().toInt();
    int C = ui->inputC5->text().toInt();
    int D = ui->inputD5->text().toInt();

    QString gate1 = ui->Gate13->currentText();
    QString gate2 = ui->Gate14->currentText();
    QString gate3 = ui->Gate15->currentText();
    QString gate4 = ui->Gate16->currentText();
    QString gate5 = ui->Gate17->currentText();

    bool error = false;
    QString errorMessage = "Recheck the number of inputs!";

    if (gate4 != "NOT") {
        error = true;
    }

    if (error) {
        ui->level5FeedbackLabel->setText(errorMessage);
        ui->level5FeedbackLabel->setStyleSheet("font-size: 14px; font-weight: bold; color: #FFFFFF; background-color:   #A93226;  border: 2px solid transparent; padding: 10px; border-radius: 5px; text-align: center; vertical-align: middle;");
        ui->CurrentOutput5->setText("X");
        return;
    }

    int intermediate1_5 = evaluateGate(gate1, A, B);
    int intermediate2_5 = evaluateGate(gate2, C, D);
    int intermediate3_5 = evaluateGate(gate3, intermediate1_5, intermediate2_5);
    int intermediate4_5 = evaluateNotGate(gate4, C);
    int finalOutput5 = evaluateGate(gate5, intermediate3_5, intermediate4_5);

    ui->CurrentOutput5->setText(QString::number(finalOutput5));
    ui->level5FeedbackLabel->clear();

    if (finalOutput5){
        ui->outputCircle5->setStyleSheet("background-color: rgb(247,255,0); border-radius: 25px;");
    }
    else{
        ui->outputCircle5->setStyleSheet("background-color: rgb(128, 128, 128); border-radius: 25px;");
    }
}

void MainWindow::updateLevel6Output()
{
    int A = ui->inputA6->text().toInt();
    int B = ui->inputB6->text().toInt();
    int C = ui->inputC6->text().toInt();
    int D = ui->inputD6->text().toInt();
    int E = ui->inputE6->text().toInt();

    QString gate1 = ui->Gate18->currentText();
    QString gate2 = ui->Gate19->currentText();
    QString gate3 = ui->Gate20->currentText();
    QString gate4 = ui->Gate21->currentText();
    QString gate5 = ui->Gate22->currentText();

    bool error = false;
    QString errorMessage = "Recheck the number of inputs!";

    if (gate4 != "NOT") {
        error = true;
    }

    if (error) {
        ui->level6FeedbackLabel->setText(errorMessage);
        ui->level6FeedbackLabel->setStyleSheet("font-size: 14px; font-weight: bold; color: #FFFFFF; background-color:   #A93226;  border: 2px solid transparent; padding: 10px; border-radius: 5px; text-align: center; vertical-align: middle;");
        ui->CurrentOutput6->setText("X");
        return;
    }
    int intermediate1_6 = evaluateGate(gate1, A, B);
    int intermediate2_6 = evaluateGate(gate2, C, D);
    int intermediate3_6 = evaluateGate(gate3, intermediate1_6, intermediate2_6);
    int intermediate4_6 = evaluateNotGate(gate4, E);
    int finalOutput6 = evaluateGate(gate5, intermediate3_6, intermediate4_6);

    ui->CurrentOutput6->setText(QString::number(finalOutput6));
    ui->level6FeedbackLabel->clear();

    if (finalOutput6){
        ui->outputCircle6->setStyleSheet("background-color: rgb(247,255,0); border-radius: 25px;");
    }
    else{
        ui->outputCircle6->setStyleSheet("background-color: rgb(128, 128, 128); border-radius: 25px;");
    }
}

void MainWindow::submitLevel()
{
    int targetOutput = 0;
    int currentOutput = 0;
    QLabel* feedbackLabel = nullptr;
    QPushButton* levelcol;

    switch (currentLevel) {
    case 1:
        targetOutput = ui->TargetOutput1->text().toInt();
        currentOutput = ui->CurrentOutput1->text().toInt();
        feedbackLabel = ui->level1FeedbackLabel;
        levelcol = ui-> levelButton1;
        break;
    case 2:
        targetOutput = ui->TargetOutput2->text().toInt();
        currentOutput = ui->CurrentOutput2->text().toInt();
        feedbackLabel = ui->level2FeedbackLabel;
        levelcol = ui-> levelButton2;
        break;
    case 3:
        targetOutput = ui->TargetOutput3->text().toInt();
        currentOutput = ui->CurrentOutput3->text().toInt();
        feedbackLabel = ui->level3FeedbackLabel;
        levelcol = ui-> levelButton3;
        break;
    case 4:
        targetOutput = ui->TargetOutput4->text().toInt();
        currentOutput = ui->CurrentOutput4->text().toInt();
        feedbackLabel = ui->level4FeedbackLabel;
        levelcol = ui-> levelButton4;
        break;
    case 5:
        targetOutput = ui->TargetOutput5->text().toInt();
        currentOutput = ui->CurrentOutput5->text().toInt();
        feedbackLabel = ui->level5FeedbackLabel;
        levelcol = ui-> levelButton5;
        break;
    case 6:
        targetOutput = ui->TargetOutput6->text().toInt();
        currentOutput = ui->CurrentOutput6->text().toInt();
        feedbackLabel = ui->level6FeedbackLabel;
        levelcol = ui-> levelButton6;
        break;
    default:
        return;
    }

    if (currentOutput == targetOutput) {
        feedbackLabel->setText("Correct! Level Cleared!");
        feedbackLabel->setStyleSheet("font-size: 14px; font-weight: bold; color: #FFFFFF; background-color: #1E8449; border: 2px solid transparent; padding: 10px; border-radius: 5px; text-align: center; vertical-align: middle;");
        levelcol->setStyleSheet("background-color: #1E8449; color: #FFFFFF; font-size: 18px; font-weight: bold; border: 2px solid white; border-radius: 10px; padding: 10px 20px;");
    } else {
        feedbackLabel->setText("Incorrect. Try Again.");
        feedbackLabel->setStyleSheet("font-size: 14px; font-weight: bold; color: #FFFFFF; background-color:   #A93226;  border: 2px solid transparent; padding: 10px; border-radius: 5px; text-align: center; vertical-align: middle;");
    }
}








