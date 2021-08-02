#include<iostream>
#include<string>
using namespace std;

//Node creation
template<typename T>
class mapNode{
    public:
        string key;
        T value;
        mapNode* next;

        mapNode(string key, T value){
            this->key = key;
            this->value = value;
            next = NULL;
        }

        ~mapNode(){
            delete next;
        }
};

//map class
template <typename T>
class ourMap{
    public:
        int count; 
        int numBuckets;
        mapNode<T>** buckets;

        ourMap(){
            count = 0;
            numBuckets = 5;
            buckets = new mapNode<T>*[numBuckets];
            //intialize buckets
            for(int i = 0; i < numBuckets; i++){
                buckets[i] = NULL;
            }
        }

        ~ourMap(){
            for(int i = 0; i < numBuckets; i++){
                delete buckets[i];
            }
            delete []buckets;
        }

        private:
        //function to claculate hashcode corresponding to given key
        int getBucketIndex(string key){
            int hashcode = 0;
            int coeff = 1;

            for(int i = key.length() - 1; i >=0; i--){
                hashcode += key[i] * coeff;
                hashcode = hashcode % numBuckets;
                coeff *= 37;
                coeff = coeff % numBuckets;
            }
            //cout << hashcode % numBuckets << endl;
            return hashcode % numBuckets;
        }

        public:
        //fucntion to insert into map
        void insert(string key, T value){
            int bucketIndex = getBucketIndex(key);
            mapNode<T>* head = buckets[bucketIndex];

            while(head != NULL){
                if(head->key == key){
                    head->value = value;
                    return;
                }
                head = head->next;
            }
            mapNode<T>* temp = buckets[bucketIndex];
            mapNode<T>* node = new mapNode<T>(key, value);
            node->next = temp;
            buckets[bucketIndex] = node;
            count++;
        }

        //function to remove element
        T remove(string key){
            int bucketIndex = getBucketIndex(key);
            mapNode<T>* head = buckets[bucketIndex];
            mapNode<T>* temp = NULL;

            while(head != NULL){
                if(head->key == key){
                    int v = head->value;
                    temp->next = head->next;
                    delete head;
                    buckets[bucketIndex] = temp;
                    count--;
                    return v;
                }
                temp = head;
                head = head->next;
            }
            return 0;
        }

        //function to search corresponding to key
        T search(string key){
            int bucketIndex = getBucketIndex(key);
            mapNode<T>* head = buckets[bucketIndex];
            while(head != NULL){
                if(head->key == key){
                    return head->value;
                }
                head = head->next;
            }
            return 0;
        }

        //function to update value
        void update(string key, T value){
            int bucketIndex = getBucketIndex(key);
            mapNode<T>* head = buckets[bucketIndex];

            while(head->key != key){
                head = head->next;
            }
            if(head != NULL){
                head->value = value;
            }
        }

        //fucntion to get size;
        int size(){
            return count;
        }
};

int main(){
    ourMap<int> umap;
    umap.insert("bcd1", 10);
    umap.insert("bcd2", 20);
    umap.insert("bcd3", 30);
    umap.insert("bcd4", 40);
    umap.insert("bcd5", 50);
    umap.insert("bcd6", 60);
    umap.insert("bcd7", 70);
    umap.insert("bcd8", 80);
    umap.insert("bcd9", 90);

    cout << umap.size() << endl;
    cout << umap.search("bcd1")<< endl;
    umap.remove("bcd1");
    cout << umap.search("bcd1") << endl;
    cout << umap.size() << endl;
    umap.update("bcd2", 979);
    cout << umap.search("bcd2") << endl;
    return 0;
}