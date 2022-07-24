#include "tabcontrol.h"
#include "ui_tabcontrol.h"

TabControl::TabControl(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TabControl)
{
    ui->setupUi(this);
    initUI();
}

TabControl::~TabControl()
{
    delete ui;
}

void TabControl::initUI()
{
    setWindowTitle("选项卡");
    QFile style(":/style.qss");
    if(style.open(QIODeviceBase::ReadOnly))
    {
        setStyleSheet(style.readAll());
    }
    // 全局布局，用于此widget中
    QHBoxLayout* gHBox = new QHBoxLayout(this);
    gHBox->setSpacing(0);       // 设置水平的各个项之间的间隔
    gHBox->setContentsMargins(0, 0, 0, 0);  // 去掉布局的边框

    // 左边的布局，按钮
    QVBoxLayout* vBox = new QVBoxLayout;
    vBox->setSpacing(0);    // 设置按钮之间的上下间隔为0
    vBox->setContentsMargins(0, 0, 0, 0);
    QStringList tabStr = {"主页", "参数", "调试", "设置", "日志"};

    for(int i = 0; i < tabStr.size(); i++)
    {
        QToolButton* btn = new QToolButton(this);
        btn->setText(tabStr.at(i));
        btn->setMaximumWidth(100);
        btn->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Expanding);
        QIcon icon(QString(":/img/%1.png").arg(tabStr.at(i)));
        btn->setIcon(icon);
        btn->setIconSize(btn->size());
        btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        m_toolBtnGrp.addButton(btn);
        vBox->addWidget(btn);
    }
    vBox->addStretch(-1);

    // 右边的布局
    QWidget* rightWgt = new QWidget;

    gHBox->addLayout(vBox);
    gHBox->addWidget(rightWgt);
}

