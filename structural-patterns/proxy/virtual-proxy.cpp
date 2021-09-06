#include <bits/stdc++.h>

using namespace std;

struct Image
{
    virtual void draw() = 0;
};

struct Bitmap : Image
{
    Bitmap(string _file_name)
    {
        cout << "[Bitmap] Loading "<< _file_name << " ...." << endl;
    }

    void draw() override
    {
        cout << "[Bitmap] Drawing ...." << endl;
    }   

};

struct LazzyBitmap : public Image
{
    LazzyBitmap(string _file_name) : file_name{_file_name}
    {
        cout << "[LazzyBitmap] ctor..." << endl;
    }

    void draw() override
    {
        cout << "[LazzyBitmap] draw..." << endl;
        if (bit_map == nullptr)
            bit_map = make_shared<Bitmap>(file_name);
        
        bit_map->draw();
    }
private:
    string file_name;
    shared_ptr<Bitmap> bit_map{nullptr};
};

int main(int argc, char **argv)
{
    LazzyBitmap lz_bit_map{"picachu.png"};
    lz_bit_map.draw();  

    return 0;
}