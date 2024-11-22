#include <stdin.h>
using namespace std;
struct node{
	node *fail;
	node *ch[K]; //usually k=26, cuz 26 lowercase letters
	int count;
	node(){
		fail = NULL;
		memset(ch , NULL , sizeof(ch));
		count = 0;
	}
};
node *superRoot, *root;   
void insert(char* str){ 
	node *t = root;
	int len = strlen(str);
	for(int i = 0 ; i < len ; i ++){
		
		int x = str[i] - 'a';  //using ASCII 
		if(t -> ch[x] == NULL){
			t -> ch[x] = new node;
		}
		t = t -> ch[x];
	}
	t-> count ++;
}
void build_failurefunction(){  
	
	queue<node *> q;   //bfs
	q.push(root);
	
	while(!q.empty()){
		node *t;
		t = q.front();
		q.pop();
	
		for(int i = 0 ; i < K ; i ++){
			if(t->ch[i]){
				t->ch[i]->fail = t->fail->ch[i];
				q.push(t->ch[i]);
			}
			else{
				t->ch[i] = t->fail->ch[i];
			}
		}
	}
}
int query(char *str){  
	
	int ans = 0;
	node *t = root;
	int len = strlen(str);
	
	for(int i = 0 ; i < len;  i++){
		int x = str[i] - 'a';
		t = t->ch[x];
	
		for(node *u = t ; u -> count != -1 ; u = u->fail){
			ans += u->count;
			u->count = -1;
		}
	}
	return ans;
}
