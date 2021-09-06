#include <bits/stdc++.h>
using namespace std;

struct Strategy
{
    virtual ~Strategy() = default;
    virtual void start(stringstream& ss) 
    {

    }

    virtual void add(stringstream& ss, const string& text) = 0;
    
    virtual void end(stringstream& ss) 
    {

    }
};

struct HtmlStrategy : Strategy
{
    virtual void start(stringstream& ss) 
    {
        ss << "<html>\n";
    }
    virtual void add(stringstream& ss, const string& text) override
    {
        ss << "  <li>" << text << "</li>\n";
    }

    virtual void end(stringstream& ss) 
    {
        ss << "<html>\n";
    }
};

struct MarkdownStrategy : Strategy
{
    void add(stringstream& ss, const string& _text) override
    {
        ss << " * " << _text << "\n";
    }
};

template <typename T>
struct TextConverter
{
    TextConverter() {}

    void convert(const vector<string>& _list)
    {
        strategy.start(ss);
        for (auto e : _list)
        {
            strategy.add(ss, e);
        }
        strategy.end(ss);
    }

    string str() const
    {
        return ss.str();
    }

    void clear()
    {
        ss.str("");
        ss.clear();
    }
private:
    stringstream ss;
    T strategy;
};

int main(int argc, char **argv)
{
    TextConverter<MarkdownStrategy> md_converter;
    TextConverter<HtmlStrategy> html_converter;
    vector<string> texts{"Hanoi", "HCM", "Da Nang", "Quy Nhon"};

    md_converter.convert(texts);
    cout << md_converter.str() << endl;
    
    html_converter.convert(texts);
    cout << html_converter.str() << endl;

    return 0;
}