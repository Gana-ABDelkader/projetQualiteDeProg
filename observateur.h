#ifndef OBSERVATEUR_H
#define OBSERVATEUR_H


class observateur
{public:
    virtual ~observateur() = default;
    virtual void observe() const;

};

#endif