#include <bits/stdc++.h>

using namespace std;

// These are some of the classes of a complex 3rd-party video
// conversion framework. We don't control that code, therefore
// can't simplify it.

struct VideoFile
{
    const string TAG = "[VideoFile] ";
    VideoFile(string _file_name)
    {
        cout << TAG + "reading video file..." << endl;
    }
};

class CompressionCodec
{
public:
    CompressionCodec() {}
    ~CompressionCodec() {}

    virtual string str() = 0;
};

struct MPEG4CompressionCodec : public CompressionCodec
{
    const string TAG = "[MPEG4CompressionCodec] ";

    MPEG4CompressionCodec() {}
    ~MPEG4CompressionCodec() {}

    string str() override
    {
        cout << TAG + "is processing" << endl;
        return string("");
    }
};

struct OggCompressionCodec : public CompressionCodec
{
    OggCompressionCodec() {}
    ~OggCompressionCodec() {}
    const string TAG = "[OggCompressionCodec] ";
    string str() override
    {
        cout << TAG + "is processing" << endl;
        return string("");
    }
};

struct CodecFactory
{
    string extract(shared_ptr<VideoFile> _video_file)
    {
        cout << "[CodecFactory] extracting video file..." << endl;
        return string("extract");
    }
};

struct BitrateReader
{
    static vector<char> read(shared_ptr<VideoFile> _video_file, string _source_codec)
    {
        cout << "[BitrateReader] reading video file ..." << endl;
        return vector<char>();
    }

    static vector<char> convert(vector<char>& v, shared_ptr<CompressionCodec> dest_codec)
    {
        cout << "[BitrateReader] converting video file ..." << endl;
        
        dest_codec->str();

        return vector<char>();
    }

};

struct AudioMixer
{
    static bool fix(vector<char>& vec)
    {
        cout << "[AudioMixer] fixed" << endl;
        return true;
    }
};


// We create a facade class to hide the framework's complexity
// behind a simple interface. It's a trade-off between
// functionality and simplicity.
struct VideoConverter 
{
    static bool convert(string _file, string _format)
    {
        
        shared_ptr<VideoFile> video_file(new VideoFile{_file});
        shared_ptr<CodecFactory> codec_factory{new CodecFactory};
        string source_codec = codec_factory->extract(video_file);

        shared_ptr<CompressionCodec> dest_codec;

        if (_format == string("mp4"))
            dest_codec = make_shared<MPEG4CompressionCodec>();
        else
            dest_codec = make_shared<MPEG4CompressionCodec>();

        vector<char> in_buffer = BitrateReader::read(video_file, source_codec);
        vector<char> out_buff = BitrateReader::convert(in_buffer, dest_codec);
        bool fix_audio = AudioMixer::fix(out_buff);

        return fix_audio;
    }
};

int main(int argc, char **argv)
{

    // Application classes don't depend on a billion classes
    // provided by the complex framework. Also, if you decide to
    // switch frameworks, you only need to rewrite the facade class.
    VideoConverter::convert("sample.wav", "mp4");

    return 0;
}