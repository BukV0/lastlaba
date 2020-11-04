#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class LineNumberArea;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    //void lineNumberAreaPaintEvent(QPaintEvent *event);
    //int lineNumberAreaWidth();
    ~MainWindow();

private slots:
   // void updateLineNumberAreaWidth(int newBlockCount);
    //void updateLineNumberArea(const QRect &rect, int dy);


    void highlightCurrentLine();
    void on_actionCancel_triggered();


    void on_actionclose_triggered();

    void on_actionRepeat_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPast_triggered();

    void on_actionSelect_All_triggered();

    void on_actionWord_wrap_toggled(bool arg1);

    void on_actionfont_triggered();

private:
    Ui::MainWindow *ui;
    QWidget *lineNumberArea;
};
/*class LineNumberArea : public QWidget
{
public:
    LineNumberArea(MainWindow *editor) : QWidget(editor)
    {}

    QSize sizeHint() const override
    {
        return QSize(codeEditor->lineNumberAreaWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event) override
    {
        codeEditor->lineNumberAreaPaintEvent(event);
    }

private:
    MainWindow *codeEditor;
};*/
#endif // MAINWINDOW_H
