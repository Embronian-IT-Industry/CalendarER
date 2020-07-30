#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMouseEvent>
#include <QTime>
#include <QDateTime>
#include <QTimerEvent>
#include <QTimer>
#include <QTimeZone>

#include "QStandardItemModel"
#include "QStandardItem"

#include <unistd.h>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void timerEvent(QTimerEvent *);

private slots:
    void on_pushButton_close_clicked();
private:
    Ui::MainWindow *ui;

    QTime m_startTime;

    QString updateTime(int _ms);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
};
#endif // MAINWINDOW_H
