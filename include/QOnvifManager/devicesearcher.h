#ifndef ONVIF_DEVICESEARCHER_H
#define ONVIF_DEVICESEARCHER_H

#include <QObject>
#include <QUdpSocket>

namespace ONVIF {
class DeviceSearcher : public QObject
{
    Q_OBJECT
public:
    static DeviceSearcher* searcher;
    explicit DeviceSearcher(QObject* parent = nullptr);
    static DeviceSearcher*     instance();
    static QList<QHostAddress> getHostAddress();
    ~DeviceSearcher();

    void sendSearchMsg();
signals:
    void receiveData(const QHash<QString, QString>& data);
    void deviceSearchingEnded();
public slots:
private slots:
    void readPendingDatagrams();

private:
    QList<QUdpSocket*> mUdpSockets;
};
} // namespace ONVIF
#endif // ONVIF_DEVICESEARCHER_H
