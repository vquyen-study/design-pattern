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

// template <typename T>
struct TextConverter
{
    enum class ConverterType
    {
        HTML_CONVERTER,
        MARKDOWN_CONVERTER,
    };

    TextConverter() : strategy{nullptr} {}

    void select_converter(ConverterType conv)
    {
        switch (conv)
        {
        case ConverterType::HTML_CONVERTER:
            strategy = make_unique<HtmlStrategy>();
            break;
        case ConverterType::MARKDOWN_CONVERTER:
            strategy = make_unique<MarkdownStrategy>();
            break;
        }
    }

    void convert(const vector<string>& _list)
    {
        strategy->start(ss);
        for (auto e : _list)
        {
            strategy->add(ss, e);
        }
        strategy->end(ss);
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
    unique_ptr<Strategy> strategy;
};

int main(int argc, char **argv)
{
    TextConverter converter;
    vector<string> texts{"Hanoi", "HCM", "Da Nang", "Quy Nhon"};

    converter.select_converter(TextConverter::ConverterType::HTML_CONVERTER);
    converter.convert(texts);
    cout << converter.str() << endl;

    converter.clear();
    converter.select_converter(TextConverter::ConverterType::MARKDOWN_CONVERTER);
    converter.convert(texts);
    cout << converter.str() << endl;

    return 0;
}