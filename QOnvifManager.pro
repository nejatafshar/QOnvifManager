#-------------------------------------------------
#
# Project created by QtCreator 2017-01-15T14:47:20
#
#-------------------------------------------------

QT       += core network xml xmlpatterns

CONFIG += c++11
CONFIG += staticlib

#DEFINES += QT_DLL QT_NETWORK_LIB QT_HELP_LIB QT_SCRIPT_LIB QT_WIDGETS_LIB QT_XML_LIB QT_XMLPATTERNS_LIB ONVIFC_LIB

contains(QT_ARCH, i386): {
    CONFIG(release, debug|release): DESTDIR = $$PWD/../../bin/32/release
    else:CONFIG(debug, debug|release): DESTDIR = $$PWD/../../bin/32/debug
}else{
    CONFIG(release, debug|release): DESTDIR = $$PWD/../../bin/64/release
    else:CONFIG(debug, debug|release): DESTDIR = $$PWD/../../bin/64/debug
}

TARGET = QOnvifManager

TEMPLATE = lib

#DEFINES += QONVIFMANAGER_LIBRARY

unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH += include
INCLUDEPATH += include/QOnvifManager
INCLUDEPATH += include/QOnvifManager/device_management
INCLUDEPATH += include/QOnvifManager/media_management
INCLUDEPATH += include/QOnvifManager/ptz_management

SOURCES += \
    src/devicemanagement.cpp \
    src/devicesearcher.cpp \
    src/qonvifdevice.cpp \
    src/qonvifmanager.cpp \
    src/device_management/capabilities.cpp \
    src/device_management/networkinterfaces.cpp \
    src/device_management/networkprotocols.cpp \
    src/device_management/systemdateandtime.cpp \
    src/device_management/systemfactorydefault.cpp \
    src/device_management/systemreboot.cpp \
    src/device_management/user.cpp \
    src/device_management/networkntp.cpp \
    src/device_management/networkhostname.cpp \
    src/device_management/networkdiscoverymode.cpp \
    src/device_management/networkdns.cpp \
    src/media_management/audioencoderconfiguration.cpp \
    src/media_management/audioencoderconfigurationoptions.cpp \
    src/media_management/audioencoderconfigurations.cpp \
    src/media_management/audiosourceconfiigurations.cpp \
    src/media_management/profile.cpp \
    src/media_management/profiles.cpp \
    src/media_management/streamuri.cpp \
    src/media_management/videoencoderconfiguration.cpp \
    src/media_management/videoencoderconfigurationoptions.cpp \
    src/media_management/videoencoderconfigurations.cpp \
    src/media_management/videosourceconfiguration.cpp \
    src/media_management/videosourceconfigurations.cpp \
    src/ptz_management/absolutemove.cpp \
    src/ptz_management/configuration.cpp \
    src/ptz_management/configurations.cpp \
    src/ptz_management/continuousmove.cpp \
    src/ptz_management/gotohomeposition.cpp \
    src/ptz_management/gotopreset.cpp \
    src/ptz_management/node.cpp \
    src/ptz_management/nodes.cpp \
    src/ptz_management/preset.cpp \
    src/ptz_management/presets.cpp \
    src/ptz_management/relativemove.cpp \
    src/ptz_management/removepreset.cpp \
    src/ptz_management/stop.cpp \
    src/client.cpp \
    src/mediamanagement.cpp \
    src/message.cpp \
    src/messageparser.cpp \
    src/ptzmanagement.cpp \
    src/service.cpp \
    src/device_management/systemscopes.cpp \
    src/ptz_management/homeposition.cpp \
    src/device_management/networkdefaultgateway.cpp \
    src/media_management/imagesetting.cpp \
    src/media_management/imagesettingoptions.cpp


HEADERS += \
    include/qonvifdevice.hpp \
    include/qonvifmanager.hpp \
    include/QOnvifManager/devicesearcher.h \
    include/QOnvifManager/devicemanagement.h \
    include/QOnvifManager/device_management/capabilities.h \
    include/QOnvifManager/device_management/networkinterfaces.h \
    include/QOnvifManager/device_management/networkprotocols.h \
    include/QOnvifManager/device_management/systemdateandtime.h \
    include/QOnvifManager/device_management/systemfactorydefault.h \
    include/QOnvifManager/device_management/systemreboot.h \
    include/QOnvifManager/device_management/user.h \
    include/QOnvifManager/device_management/networkdiscoverymode.h \
    include/QOnvifManager/device_management/networkhostname.h \
    include/QOnvifManager/device_management/networkntp.h \
    include/QOnvifManager/device_management/networkdns.h \
    include/QOnvifManager/media_management/audioencoderconfiguration.h \
    include/QOnvifManager/media_management/audioencoderconfigurationoptions.h \
    include/QOnvifManager/media_management/audioencoderconfigurations.h \
    include/QOnvifManager/media_management/audiosourceconfigurations.h \
    include/QOnvifManager/media_management/profile.h \
    include/QOnvifManager/media_management/profiles.h \
    include/QOnvifManager/media_management/streamuri.h \
    include/QOnvifManager/media_management/videoencoderconfiguration.h \
    include/QOnvifManager/media_management/videoencoderconfigurationoptions.h \
    include/QOnvifManager/media_management/videoencoderconfigurations.h \
    include/QOnvifManager/media_management/videosourceconfiguration.h \
    include/QOnvifManager/media_management/videosourceconfigurations.h \
    include/QOnvifManager/ptz_management/absolutemove.h \
    include/QOnvifManager/ptz_management/configuration.h \
    include/QOnvifManager/ptz_management/configurations.h \
    include/QOnvifManager/ptz_management/continuousmove.h \
    include/QOnvifManager/ptz_management/gotohomeposition.h \
    include/QOnvifManager/ptz_management/gotopreset.h \
    include/QOnvifManager/ptz_management/node.h \
    include/QOnvifManager/ptz_management/nodes.h \
    include/QOnvifManager/ptz_management/preset.h \
    include/QOnvifManager/ptz_management/presets.h \
    include/QOnvifManager/ptz_management/relativemove.h \
    include/QOnvifManager/ptz_management/removepreset.h \
    include/QOnvifManager/ptz_management/stop.h \
    include/QOnvifManager/client.h \
    include/QOnvifManager/mediamanagement.h \
    include/QOnvifManager/message.h \
    include/QOnvifManager/messageparser.h \
    include/QOnvifManager/ptzmanagement.h \
    include/QOnvifManager/qringbuffer_p.h \
    include/QOnvifManager/service.h \
    include/QOnvifManager/device_management/systemscopes.h \
    include/QOnvifManager/ptz_management/homeposition.h \
    include/QOnvifManager/device_management/networkdefaultgateway.h \
    include/QOnvifManager/media_management/imagesetting.h \
    include/QOnvifManager/media_management/imagesettingoptions.h


#unix {
#    TEMPDIR         = $$PRJDIR/tmp/unix/$$TARGET
#    QMAKE_CFLAGS   += -std=gnu99
#    QMAKE_CXXFLAGS *= -Wall -Wextra -Wnon-virtual-dtor -pedantic
#    QMAKE_CXXFLAGS *= -Wcast-align -Wunused -Woverloaded-virtual
#    QMAKE_CXXFLAGS *= -Wno-unused-parameter
#    #QMAKE_CXXFLAGS *= -Wconversion
#    #QMAKE_CXXFLAGS *= -Wold-style-cast
#    macx {
#        QMAKE_CXXFLAGS *= -stdlib=libc++
#        TEMPDIR    = $$PRJDIR/tmp/osx/$$TARGET
#        CONFIG    -= app_bundle
#    }

#    XBINDIR        = xbin64
#    LIBDIR         = lib64
#}

#win32 {
#    DEFINES        *= UNICODE _WINDOWS
#    DEFINES        *= WIN32_LEAN_AND_MEAN NOMINMAX _CRT_SECURE_NO_WARNINGS

#    use_xp_sdk {
#        # old windows sdk, required for older targets (2003, xp)
#        # run as: $> qmake CONFIG+=use_xp_sdk
#        DEFINES    *= _WIN32_WINNT=0x0502 WINVER=0x0502
#    } else {
#    }

#    win32-msvc*{
#        QMAKE_CXXFLAGS *= /Gy /GF
#        QMAKE_LFLAGS   *= /OPT:REF /OPT:ICF
#    }
#    *-g++*{
#        # mingw or msys
#        CONFIG         -= debug debug_and_release
#        QMAKE_CXXFLAGS *= -Wall -Wextra -Wnon-virtual-dtor -pedantic
#        QMAKE_CXXFLAGS *= -Wcast-align -Wunused -Woverloaded-virtual
#        QMAKE_CXXFLAGS *= -Wno-unused-parameter
#    }
#    contains(QT_ARCH, i386) {
#        TEMPDIR     = $$PRJDIR/tmp/win32/$$TARGET
#        XBINDIR     = xbin32
#        LIBDIR      = lib32
#    }
#    contains(QT_ARCH, x86_64) {
#        DEFINES    *= WIN64
#        TEMPDIR     = $$PRJDIR/tmp/win64/$$TARGET
#        XBINDIR     = xbin64
#        LIBDIR      = lib64
#    }
#}
