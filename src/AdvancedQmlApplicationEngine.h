#pragma once
#include <QDir>
#include <QFileSystemWatcher>
#include <QList>
#include <QQmlApplicationEngine>
#include <QString>
#include <QUrl>
#include <QUuid>

class QFileSystemWatcher;
class QTimer;


class AdvancedQmlApplicationEngine : public QQmlApplicationEngine {

	Q_OBJECT

 public:
	explicit AdvancedQmlApplicationEngine(QObject *parent = nullptr);
	void setHotReload(bool enable);
	void loadRootItem(const QString &rootItem);
	void loadRootItem(const QUrl &rootItem);
	bool hasRootItem() const;

 private slots:
	void reload();

 private:
	Q_DISABLE_COPY(AdvancedQmlApplicationEngine)

	void init();
	void connectWatcher();
	void disconnectWatcher();
	QList<QString> findQmlFilesRecursive(const QDir &dir) const;

	QUrl mRootUrl;
	bool mHotReloading;
	QFileSystemWatcher *mpWatcher;
	QTimer *mpTimer;
};
