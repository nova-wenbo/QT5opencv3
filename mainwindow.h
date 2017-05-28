/************************************************************************************
 *  author : Dave
 *  Email : nova_wangwenbo@163.com
 *  Address : Xi'an Aeronautical University
 *  Date : 20170525
 * **********************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_open_clicked();

    void on_imgShow_clicked();

    void on_filpImg_clicked();

    void on_close_clicked();

    void on_console_one_sliderMoved(int position);

    void on_console_two_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
};

#endif

