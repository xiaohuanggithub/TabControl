#ifndef TABCONTROL_H
#define TABCONTROL_H

#include <QWidget>
#include <QToolButton>
#include <QButtonGroup>
#include <QActionGroup>
#include <QSplitter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFile>
#include <QIcon>

QT_BEGIN_NAMESPACE
namespace Ui { class TabControl; }
QT_END_NAMESPACE

class TabControl : public QWidget
{
    Q_OBJECT

public:
    TabControl(QWidget *parent = nullptr);
    ~TabControl();

private:
    void initUI();

private:
    Ui::TabControl *ui;
    QButtonGroup m_toolBtnGrp;
};
#endif // TABCONTROL_H
