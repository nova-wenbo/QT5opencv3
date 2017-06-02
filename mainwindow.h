/************************************************************************************
 *  author : Dave
 *  Email : nova_wangwenbo@126.com
 *  Address : Xi'an Aeronautical University
 *  Date : 20170527
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

    void on_collection_clicked();

    void on_console_one_sliderMoved(int position);

    void on_console_two_sliderMoved(int position);

    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    cv::VideoCapture capture(0);
    cv::Mat frame;
};

#endif

