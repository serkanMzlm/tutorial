#include "project_type.h"
#include "rosnode.h"

int main(int argc, char *argv[]){
    QGuiApplication app(argc, argv);
    rclcpp::init(argc, argv);
    QQmlContext* context;
    QQmlApplicationEngine engine;
    RosNode node;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    context = engine.rootContext();
    context->setContextProperty("_rosNode", &node);
    engine.load(url);
    return app.exec();
}
