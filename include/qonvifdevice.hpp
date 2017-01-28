#ifndef QONVIFDEVICE_HPP
#define QONVIFDEVICE_HPP

#include <QDateTime>
#include <QObject>

namespace ONVIF {
class DeviceManagement;
class MediaManagement;
}

class QOnvifDevice : public QObject
{
public:

    //device management
    struct DeviceInformation{
        QString manufacturer;
        QString model;
        QString firmwareVersion;
        QString serialNumber;
        QString hardwareId;
    };

    struct DeviceCapabilities{
        //ptz capabilities
        QString ptzAddress;

        //imaging capabilities
        QString imagingXAddress;

        //media capabilities
        QString mediaXAddress;
        bool rtpMulticast;
        bool rtpTcp;
        bool rtpRtspTcp;

        //public capabilities
        QString deviceXAddr;
        bool iPFilter;
        bool zeroConfiguration;
        bool iPVersion6;
        bool dynDNS;
        bool discoveryResolve;
        bool systemLogging;
        bool firmwareUpgrade;
        int major;
        bool minor;
        bool httpFirmwareUpgrade;
        bool httpSystemBackup;
        bool httpSystemLogging;
        bool httpSupportInformation;
        int inputConnectors;
        int relayOutputs;
        bool tls11;
        bool tls22;
        bool onboardKeyGeneration;
        bool accessPolicyConfig;
        bool x509Token;
        bool samlToken;
        bool kerberosToken;
        bool relToken;
        bool tls10;
        bool dot1x;
        bool remoteUserHanding;
        bool systemBackup;
        bool discoveryBye;
        bool remoteDiscovery;
    };

    struct DeviceProbeData{
        QString iendPointAddress;
        QString itypes;
        QString ideviceIp;
        QString ideviceServiceAddress;
        QString iscopes;
        QString imetadataVersion;
    };

    struct DateTime{
        QDateTime utcTime;
        QDateTime localTime;
    };

    //media management

    struct MediaConfig
    {
        struct Audio
        {
            struct EncodingOptions{
                QList< QList<int> > bitratList;
                QList< QList<int> > sampleRateList;
                enum Encoding {G711,G726,AAC};
                QList<Encoding> encoding;
            };
            struct EncoderConfig{
                QList<QString> token;
                QList<QString> name;
                QList<int> useCount;
                QList<QString> encoding;
                QList<int> bitrate;
                QList<int> sampleRate;
                QList<QString> type;
                QList<QString> ipv4Address;
                QList<QString> ipv6Address;
                QList<int> port;
                QList<int> ttl;
                QList<bool> autoStart;
                QList<QString> sessionTimeout;
            };
            struct SourceConfig{
                QList<QString> token;
                QList<QString> name;
                QList<int> useCount;
                QList<QString> sourceToken;
            };
            EncodingOptions encodingOptions;
            EncoderConfig encodingConfig;
            SourceConfig sourceConfig;
        };

        struct Video
        {
            struct EncodingOptions{
                int qualityRangeMin;
                int qulityRangeMax;
                QList<int> resAvailableWidth;
                QList<int> resAvailableHeight;
                int govLengthRangeMin;
                int govLengthRangeMax;
                int frameRateRangeMin;
                int frameRateRangeMax;
                int encodingIntervalRangeMin;
                int encodingIntervalRangeMax;
                enum H264ProfilesSupported {Baseline,Main,Extended,High};
                QList<H264ProfilesSupported> h264ProfilesSupported;
            };
            struct EncoderConfig{
                QList<QString> token;
                QList<QString> name;
                QList<int> useCount;
                QList<QString> encoding;
                QList<int> width;
                QList<int> height;
                QList<int> quality;
                QList<int> frameRateLimit;
                QList<int> encodingInterval;
                QList<int> bitrateLimit;
                QList<int> govLength;
                QList<QString> h264Profile;
                QList<QString> type;
                QList<QString> ipv4Address;
                QList<QString> ipv6Address;
                QList<int> port;
                QList<int> ttl;
                QList<bool> autoStart;
                QList<QString>sessionTimeout;
            };
            struct SourceConfig{
                QList<QString> name;
                QList<int> useCount;
                QList<QString> sourceToken;
                QList<QRect> bounds;
            };
            EncodingOptions encodingOptions;
            EncoderConfig encodingConfig;
            SourceConfig sourceConfig;
        };
        Audio audio;
        Video video;
    };

    QOnvifDevice();
    QOnvifDevice(QString _serviceAddress, QString _userName, QString _password, QObject* _parent);
    ~QOnvifDevice();

    //device management
    DeviceProbeData deviceProbeData();
    void setDeviceProbeData(DeviceProbeData _probeData);

    DateTime deviceDateAndTime();
    bool setDeviceDateAndTime(QDateTime _dateAndTime);

    bool refreshDeviceCapabilities();
    bool refreshDeviceInformation();

    bool resetFactoryDevice();
    bool rebootDevice();

    //media management
    bool refreshVideoConfigs();
    bool refreshAudioConfigs();

private:

    QString iuserName;
    QString ipassword;

    //device management
    ONVIF::DeviceManagement *ideviceManagement;

    DateTime idateAndTime;
    DeviceProbeData ideviceProbeData;
    DeviceInformation ideviceInformation;
    DeviceCapabilities ideviceCapabilities;

    //media management
    ONVIF::MediaManagement *imediaManagement;
    MediaConfig imediaConfig;


};

#endif // QONVIFDEVICE_HPP
