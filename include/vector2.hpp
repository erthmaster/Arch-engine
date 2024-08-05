typedef struct Vec2
{
    float x;
    float y;
    float x1;
    float y1;

    public:
        Vec2(float x, float y)
        : x(x), y(y) {};

        Vec2(float x, float y, float x1, float y1)
        : x(x), y(y), x1(x1), y1(y1) {};
        
};

Vec2 v = {1,1};