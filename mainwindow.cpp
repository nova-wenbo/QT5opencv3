/************************************************************************************
 *  author : Dave
 *  Email : nova_wangwenbo@126.com
 *  Address : Xi'an Aeronautical University
 *  Date : 20170527
 * **********************************************************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <QFileDialog>
#include <QLineEdit>
#include <QString>
#include <QMessageBox>
#include <QRadioButton>
#include <QImage>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
/**/
void MainWindow::on_open_clicked()
{
    QString strFileName = QFileDialog::getOpenFileName(this,tr("打开图片"),".",tr("图片文件 (*.png *.jpg *.jpeg *.bmp)"));
    QLineEdit *pLineEdit = (QLineEdit *)ui->dirEdit;
    pLineEdit->setText(strFileName);
}
/*提示警告*/
void MainWindow::on_imgShow_clicked()
{
    QLineEdit *pLineEdit = (QLineEdit *)ui->dirEdit;
    QString strFileName = pLineEdit->text();
    if(strFileName.isEmpty())
    {
        QMessageBox::about(this,tr("警告"),tr("请先选择文件"));
        return;
    }
    cv::Mat image = cv::imread(strFileName.toLatin1().data());
    if(!image.data)
    {
        QMessageBox::about(this,tr("警告"),tr("图片打开错误"));
        return;
    }
    cv::namedWindow("原始图片");
    cv::imshow("原始图片", image);

  //    QImage img= QImage((const unsigned char*)(image.data),
   //   image.cols,image.rows,QImage::Format_RGB888);
  //    ui->QImgShow->setPixmap(QPixmap::fromImage(img).scaled(ui->QImgShow->size()));
}
/*图像处理*/
void MainWindow::on_filpImg_clicked()
{
    QLineEdit *pLineEdit = (QLineEdit *)ui->dirEdit;
    QString strFileName = pLineEdit->text();
    if(strFileName.isEmpty())
    {
        QMessageBox::about(this,tr("警告"),tr("请先选择文件"));
        return;
    }
    cv::Mat image = cv::imread(strFileName.toLatin1().data());
    if(!image.data)
    {
        QMessageBox::about(this,tr("警告"),tr("图片打开错误"));
        return;
    }
    cv::Mat result;

    int iflipType = 2;
    if(ui->radioH->isChecked())
    {
        iflipType = 1;
        cv::flip(image,result,iflipType);
      //  cv::namedWindow("图片");
    }else if(ui->radioV->isChecked()){
        iflipType = 0;
        cv::flip(image,result,iflipType);
       // cv::namedWindow("图片");
    }else if(ui->radioVH->isChecked()){
        iflipType = -1;
        cv::flip(image,result,iflipType);
       // cv::namedWindow("图片");
    }
    else if(ui->radioH_4->isChecked()){ /*灰度处理*/
        cvtColor(image, result, CV_BGR2GRAY );
       // cv::namedWindow("灰度图片");
    }
    else if(ui->radioH_2->isChecked()){
        cvtColor(image, result, CV_BGR2GRAY);
        blur(image, result , cv::Size(3,3));    /*低通滤波*/
        Canny(image, result, 3, 3);
    }
    else if(ui->radioH_3->isChecked()){  /*腐蚀处理*/
        cv::Mat out;
        out = getStructuringElement(cv::MORPH_RECT, cv::Size(15,15));
        erode(image,result, out);
    }
    cv::imshow("图像处理", result);

}

/*退出软件*/
void MainWindow::on_close_clicked()
{
   // close();
    exit(0);
}
/*亮度*/
void MainWindow::on_console_one_sliderMoved(int position)
{
    char alpha = 1;
    QLineEdit *pLineEdit = (QLineEdit *)ui->dirEdit;
    QString strFileName = pLineEdit->text();
    if(strFileName.isEmpty())
    {
        QMessageBox::about(this,tr("警告"),tr("请先选择文件"));
        return;
    }
    cv::Mat image = cv::imread(strFileName.toLatin1().data());
    if(!image.data)
    {
        QMessageBox::about(this,tr("警告"),tr("图片打开错误"));
        return;
    }
    ui->console_one->setMinimum(0);
    ui->console_one->setMaximum(100);

    for (int i = 0;i<image.rows;++i)
           for(int j= 0;j<image.cols;++j)
               for(int k = 0;k<3;++k)
                   image.at<cv::Vec3b>(i,j)[k] = cv::saturate_cast<uchar>(image.at<cv::Vec3b>(i,j)[k]*alpha+position);

    cv::imshow("图像处理", image);
}
/*对比度*/
void MainWindow::on_console_two_sliderMoved(int position)
{
    char date = 1;
    QLineEdit *pLineEdit = (QLineEdit *)ui->dirEdit;
    QString strFileName = pLineEdit->text();
    if(strFileName.isEmpty())
    {
        QMessageBox::about(this,tr("警告"),tr("请先选择文件"));
        return;
    }
    cv::Mat image = cv::imread(strFileName.toLatin1().data());
    if(!image.data)
    {
        QMessageBox::about(this,tr("警告"),tr("图片打开错误"));
        return;
    }
    ui->console_one->setMinimum(0);
    ui->console_one->setMaximum(100);

    for (int i = 0;i<image.rows;++i)
           for(int j= 0;j<image.cols;++j)
               for(int k = 0;k<3;++k)
                   image.at<cv::Vec3b>(i,j)[k] = cv::saturate_cast<uchar>(image.at<cv::Vec3b>(i,j)[k]*position+date);

    cv::imshow("图像处理", image);
}

void MainWindow::on_pushButton_clicked()
{
    cv::VideoCapture capture(0);
    cv::Mat frame;

    while(1)
    {
        capture >> frame;
        cv::imshow("图像", frame);
    }
}


















