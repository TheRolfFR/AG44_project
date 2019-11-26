#ifndef WARSHALLFLOYD_H
#define WARSHALLFLOYD_H
#include "Graph.h"


class WarshallFloyd
{
    public:
        WarshallFloyd();
        virtual ~WarshallFloyd();
        WarshallFloyd(const WarshallFloyd& other);
        WarshallFloyd& operator=(const WarshallFloyd& other);

        Graph execute(Graph&);

    protected:

    private:
};

#endif // WARSHALLFLOYD_H
