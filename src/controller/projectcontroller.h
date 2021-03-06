#ifndef PROJECTCONTROLLER_H
#define PROJECTCONTROLLER_H

#include "../model/project.h"
#include "../model/request.h"
#include <QDebug>
#include <QObject>
#include <QSharedPointer>
#include <qdjango/db/QDjangoModel.h>
#include <qdjango/db/QDjangoQuerySet.h>

class ProjectController : public QObject {
    Q_OBJECT

  public:
    ProjectController(QObject *parent = 0);

    QSharedPointer<QList<QSharedPointer<Project>>> getProjects();
    QSharedPointer<QList<QSharedPointer<Request>>> getRequests(int projectId);
    QSharedPointer<Project> upsertDefaultProject();
    QSharedPointer<Project> getProject(int id);

  private:
    QDjangoQuerySet<Project> projects;
    QDjangoQuerySet<Request> requests;
};

#endif // PROJECTCONTROLLER_H
