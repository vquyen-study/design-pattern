#include <bits/stdc++.h>

using namespace std;

class Graphic
{
public:
    virtual void move(int x, int y) = 0;
    virtual void draw() = 0;
    virtual string get_id() = 0;
};

class Dot : public Graphic
{
private:
    string id;
    int x, y;
public:
    Dot(string _id, int _x, int _y) : id(_id), x(_x), y(_y) 
    {

    }
    
    ~Dot() 
    {

    }

    string get_id() override
    {
        return id;
    }

    void move(int xx, int yy) override
    {
        cout << "[Dot] " << id << " is moving to (" << xx << ", " << yy << ") " << endl;
    }

    void draw() override
    {
        cout << "[Dot] " << id << " is drawing" << endl;
    }
};

class Circle : public Dot
{
public:
    Circle(string _id, int _x, int _y, int rad) : Dot{_id + "circle", _x, _y}, id{_id}, radius(rad)
    {

    }
    
    ~Circle() 
    {

    }

    void move(int xx, int yy) override
    {
        cout << "[Circle] " << id << " is moving to (" << xx << ", " << yy << ") " << endl;
    }

    void draw() override
    {
        cout << "[Circle] " << id << " is drawing" << endl;
    }
    
    string get_id() override
    {
        return id;
    }
private:
    string id;
    int radius;
};

class CompoundGraphic : public Graphic
{
public:
    CompoundGraphic(string _id) : id(_id)
    {

    }
    
    ~CompoundGraphic() 
    {

    }

    string get_id() override
    {
        return id;
    }

    void move(int xx, int yy) override
    {
        cout << "[CompoundGraphic] " << id << " is move (" << xx << ", " << yy << ")" << endl;
        for (const auto& e : g_vec)
            (e)->move(xx, yy);
    }

    void draw() override
    {
        cout << "[CompoundGraphic] " << id << " is drawing, size " << g_vec.size() << endl;
        for (const auto& e : g_vec)
            (e)->draw();
    }

    void add(Graphic* graphic)
    {
        g_vec.push_back(graphic);
    }

    //TODO : This issuse has been happend when a call to remove. Need to fix.
    void remove(Graphic* graphic)
    {
        g_vec.erase(std::remove(g_vec.begin(), g_vec.end(), graphic), g_vec.end());
        // for (auto itor = g_vec.begin(); itor != g_vec.end(); itor++)
        // {
        //     if ((*itor)->get_id() == graphic->get_id())
        //     {
        //         cout << "removing " << endl;
        //         g_vec.erase(--itor);
        //         // cout << std::distance(g_vec.begin(), itor) << endl;
        //     }
        // }
           
    }
private:
    string id;
    vector<Graphic*> g_vec;
};



int main(int argc, char **argv)
{
    CompoundGraphic compound_graphic{"compond-graphic"};
    CompoundGraphic compound_graphic2{"compond-graphic2"};

    Circle circle1{"cir1", 1, 2, 10};
    Circle circle2{"cir2", 5, 2, 10};

    Dot dot1{"dot1", 2, 3};
    Dot dot2{"dot2", 5, 3};

    compound_graphic.add(&circle1);
    compound_graphic.add(&dot1);
    compound_graphic.add(&circle1);
    compound_graphic.add(&dot2);

    compound_graphic2.add(&circle1);
    compound_graphic2.add(&dot2);

    compound_graphic.add(&compound_graphic2);
    compound_graphic.draw();

    compound_graphic2.remove(&dot2);
    compound_graphic.draw();
    compound_graphic2.draw();

    return 0;
}

