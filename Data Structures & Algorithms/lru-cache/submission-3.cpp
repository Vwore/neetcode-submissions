class List {
    public:
    int val;
    List* prev;
    List* next;
     List (int val, List* prev) {
        this->val=val;
        this->prev=prev;
        this->next = nullptr;
    }
};

class LRUCache {
public:
    List *head,*currNode;
    int listSize;
    unordered_map<int,int> mp;
    unordered_map<int,List*> l;
    // queue<int> cache;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new List(-1,nullptr);
        this->currNode = head;
        listSize=0;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
List* node = l[key];

if (currNode == node)
    return mp[key];

// Remove node
node->prev->next = node->next;
node->next->prev = node->prev;

// Add to end
node->prev = currNode;
node->next = nullptr;
currNode->next = node;
currNode = node;

return mp[key];


        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        mp[key] = value;
        if(l.find(key)==l.end())
        {
            currNode->next = new List(key,currNode);
            currNode= currNode->next;
            l[key] = currNode;
            listSize++;
            if(capacity<listSize)
            {
                int lruKey = head->next->val;
                head->next = head->next->next;
                head->next->prev=head;
                mp.erase(lruKey);
                l.erase(lruKey);
                listSize--;
            }
            
        }
        else{
                auto node = l[key];
                if(currNode!=node)  
                {currNode->next=node;
                node->prev->next = node->next;
                node->next->prev=node->prev;
                node->prev = currNode;
                currNode=currNode->next;
                currNode->next=nullptr;}
            }
    }
};
