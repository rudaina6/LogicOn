#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QMap>
#include <functional>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_tutorialButton_clicked();
    void toggleTInputs();
    void updateOutput();
    void onTabChanged(int index);
    void on_levelsButton_clicked();
    void mainBackButton_clicked();
    void openLevel1();
    void openLevel2();
    void openLevel3();
    void openLevel4();
    void openLevel5();
    void openLevel6();
    void goToLevelsPage();
    void toggleInput();
    void submitLevel();
    void updateLevel1Output();
    void updateLevel2Output();
    void updateLevel3Output();
    void updateLevel4Output();
    void updateLevel5Output();
    void updateLevel6Output();
    int evaluateGate(const QString& gate, int input1, int input2);
    int evaluateNotGate(const QString& gate, int input);
    void updateGateImage();


private:
    Ui::MainWindow *ui;
    QPushButton *input1Button;
    QPushButton *input2Button;
    QLabel *outputCircle;

    QMap<QString, std::function<int(int, int)>> gateLogic;
    QString currentGate;
    int currentLevel;

};

#endif
