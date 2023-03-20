/*
Tập tin INPUT.txt chứa số lượng tin nhắn bình chọn của khán giả cho ca sĩ mình yêu thích.
"Mã bình chọn, ca sĩ được bình chọn, thời gian bình chọn."
Hãy in ra "OUTPUT.txt" ca sĩ được bình chọn nhiều nhất.
*** Lưu ý: Dòng đầu tiên là giờ mở tổng đài bình chọn và đóng tổng đài bình chọn.
*/

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

#ifndef _VOTEMESSAGE_H
#define _VOTEMESSAGE_H

class VoteMessage
{
private:
    char *_id;
    char *_singer;
    char *_time;

public:
    // constructor
    VoteMessage();
    VoteMessage(char *id, char *singer, char *time);

    // destructor
    ~VoteMessage();

    // copy constructor
    VoteMessage(const VoteMessage &other);

    // assignment operator
    VoteMessage &operator=(const VoteMessage &other);

    // getter
    char *Id();
    char *singer();
    char *time();

    // setter
    void setId(char *id);
    void setSinger(char *singer);
    void setTime(char *time);

    // methods
    friend ofstream &operator<<(ofstream &fout, const VoteMessage message);
    friend ifstream &operator>>(ifstream &fin, VoteMessage &message);
};

#endif

VoteMessage::VoteMessage()
{
    _id = NULL;
    _singer = NULL;
    _time = NULL;
}

VoteMessage::VoteMessage(char *id, char *singer, char *time)
{
    _id = new char[strlen(id) + 1];
    strcpy(_id, id);

    _singer = new char[strlen(singer) + 1];
    strcpy(_singer, singer);

    _time = new char[strlen(time) + 1];
    strcpy(_time, time);
}

VoteMessage::~VoteMessage()
{
    if (_id != NULL)
    {
        delete[] _id;
    }

    if (_singer != NULL)
    {
        delete[] _singer;
    }

    if (_time != NULL)
    {
        delete[] _time;
    }
}

VoteMessage::VoteMessage(const VoteMessage &other)
{
    _id = new char[strlen(other._id) + 1];
    strcpy(_id, other._id);

    _singer = new char[strlen(other._singer) + 1];
    strcpy(_singer, other._singer);

    _time = new char[strlen(other._time) + 1];
    strcpy(_time, other._time);
}

// assignment operator
VoteMessage &VoteMessage::operator=(const VoteMessage &other)
{
    if (this != &other)
    {
        if (_id != NULL)
        {
            delete[] _id;
        }

        if (_singer != NULL)
        {
            delete[] _singer;
        }

        if (_time != NULL)
        {
            delete[] _time;
        }

        _id = new char[strlen(other._id) + 1];
        strcpy(_id, other._id);

        _singer = new char[strlen(other._singer) + 1];
        strcpy(_singer, other._singer);

        _time = new char[strlen(other._time) + 1];
        strcpy(_time, other._time);
    }

    return *this;
}

// getter
char *VoteMessage::Id()
{
    return _id;
}
char *VoteMessage::singer()
{
    return _singer;
}
char *VoteMessage::time()
{
    return _time;
}

// setter
void VoteMessage::setId(char *id)
{
    if (_id != NULL)
    {
        delete[] _id;
    }

    _id = new char[strlen(id) + 1];
    strcpy(_id, id);
}
void VoteMessage::setSinger(char *singer)
{
    if (_singer != NULL)
    {
        delete[] _singer;
    }

    _singer = new char[strlen(singer) + 1];
    strcpy(_singer, singer);
}
void VoteMessage::setTime(char *time)
{
    if (_time != NULL)
    {
        delete[] _time;
    }

    _time = new char[strlen(time) + 1];
    strcpy(_time, time);
}

// methods
ofstream &operator<<(ofstream &fout, const VoteMessage message)
{
    fout << message._id << " ";
    fout << message._singer << " ";
    fout << message._time << endl;
    return fout;
}

ifstream &operator>>(ifstream &fin, VoteMessage &message)
{
    char *line = new char[100];
    fin.getline(line, 100, ' ');
    // split id
    message.setId(line);

    fin.getline(line, 100);

    char *p = line + strlen(line) - 1;
    while (*p != ' ')
    {
        p--;
    }

    // split singer
    *p = '\0';
    message.setSinger(line);

    // split time
    message.setTime(p + 1);

    return fin;
}

struct Node
{
    VoteMessage data;
    Node *next;
};

class DSVote
{
private:
    Node *pHead;
    char *_openTime;
    char *_closeTime;
    char *_winner;
    int _count;

public:
    // constructor
    DSVote();

    // destructor
    ~DSVote();

    // methods
    // 1. Đọc dữ liệu từ file INPUT.txt
    void read();

    // 2. In ra ca sĩ được bình chọn nhiều nhất
    void write();

    // 3. Tìm ca sĩ được bình chọn nhiều nhất
    VoteMessage findMaxSinger();

    // 4. Thêm một tin nhắn bình chọn vào danh sách
    void add(VoteMessage message);
};

DSVote::DSVote()
{
    pHead = NULL;
    _count = 0;
    _openTime = NULL;
    _closeTime = NULL;
    _winner = NULL;
}

DSVote::~DSVote()
{
    if (pHead != NULL)
    {
        Node *p = pHead;
        while (p != NULL)
        {
            Node *q = p;
            p = p->next;
            q->data.~VoteMessage();
        }
    }
    if (_openTime != NULL)
    {
        delete[] _openTime;
    }
    if (_closeTime != NULL)
    {
        delete[] _closeTime;
    }
    if (_winner != NULL)
    {
        delete[] _winner;
    }

}

void DSVote::read()
{
    ifstream fin("INPUT1.txt");
    if (fin.is_open())
    {
        // get open time and close time
        char *open_close_time = new char[100];
        fin.getline(open_close_time, 100);
        _openTime = new char[100];
        _closeTime = new char[100];
        char *p = open_close_time;
        while (*p != ' ')
        {
            p++;
        }
        *p = '\0';
        strcpy(_openTime, open_close_time);
        strcpy(_closeTime, p + 1);

        delete[] open_close_time;

        // get vote messages
        VoteMessage message;
        while (fin >> message)
        {
            add(message);
        }
    }
    fin.close();
}

void DSVote::write()
{
    ofstream fout("OUTPUT.txt");
    if (fout.is_open())
    {
        fout << _winner << " " << _count << endl;
    }
    fout.close();
}


    // 3. Tìm ca sĩ được bình chọn nhiều nhất trong thời gian mở bình chọn
    VoteMessage DSVote:: findMaxSinger() {
        VoteMessage maxSinger;
        int maxCount = 0;
        Node *p = pHead;
        while (p != NULL) {
            int count = 0;
            Node *q = pHead;
            while (q != NULL) {
                if (strcmp(p->data.singer(), q->data.singer()) == 0) {
                    // kiểm tra thơi gian bình chọn có nằm trong [openTime, closeTime] hay không
                    if (strncmp(q->data.time(), _openTime, 5) >= 0 && strncmp(q->data.time(), _closeTime, 5) <= 0) {
                        count++;
                    }
                }
                q = q->next;
            }
            if (count > maxCount) {
                maxCount = count;
                maxSinger = p->data;
            }
            p = p->next;
        }
        _count = maxCount;
        _winner = new char[strlen(maxSinger.singer()) + 1];
        strcpy(_winner, maxSinger.singer());
        return maxSinger;

    }

    // 4. Thêm một tin nhắn bình chọn vào danh sách
    void DSVote::add(VoteMessage message) {
        Node *p = new Node;
        p->data = message;
        p->next = NULL;

        if (pHead == NULL) {
            pHead = p;
        } else {
            Node *q = pHead;
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = p;
        }

    }

int main() {
    DSVote ds;
    ds.read();
    ds.findMaxSinger();
    ds.write();
    return 0;
}