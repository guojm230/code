#pragma once
#include <iostream>
#include <queue>

/**
层序遍历，每次遍历一层，记录是否存在子节点，记录每一层子节点的个数。
 构建的树结构为：
 1
 |
 2->      3    ->4
 |        |
 5->6->7  8->9
 关键在于层次遍历时要怎么分辨一层的结束；
*/
namespace PAT_4_Counting_Leaves {
    using namespace std;
	//declare functions
	void buildTree();
	void appendChild(int pid,int cid);
	void layerSearch(int id);

	struct Node {
		int index = 0;
		Node* next = nullptr;
	};

	int N, M, i = 0, j = 0;
	Node** tree;
	queue<Node*> qu;
	int main() {
	    std::iostream::sync_with_stdio(false);
		cin>> N >> M;
		if (N == 0) return 0;
		buildTree();
		layerSearch(1);
		return 0;
	}

	//build tree from input;
	void buildTree() {
		tree = new Node*[N+1];
		for (i = 0; i < N + 1;i++) {
			tree[i] = nullptr;
		}
		int id = 0, cid = 0, children = 0;
		for (i = 0; i < M; i++) {
			cin >> id >> children;
			for (j = 0; j < children; j++) {
				cin >> cid;
				appendChild(id,cid);
			}
		}
	}

	void appendChild(int pid,int cid) {
		if (tree[pid] == nullptr) {
			tree[pid] = new Node{ cid,nullptr };
		}
		else {
			Node* temp = tree[pid];
			while (temp->next != nullptr) {
			    temp = temp->next;
			}
			temp->next = new Node{cid,nullptr};
		}
	}

	/**
	 * 层序遍历，遍历时为了区分层次，在队列中用nullptr来表示一层的结束。
	 * @param id
	 */
	void layerSearch(int id) {
	    Node *temp = new Node{id,nullptr};
	    qu.push(temp);
	    qu.push(nullptr);
	    int count = 0;
	    while(!qu.empty()){
            count = 0;
            //search a layer
            while((temp = qu.front()) != nullptr){
                qu.pop();
                while(temp != nullptr){
                    if(tree[temp->index] == nullptr){
                        count++;
                    } else {
                        qu.push(tree[temp->index]);
                    }
                    temp = temp->next;
                }
            }
            qu.pop();
            cout<<count;
            if(!qu.empty()){
                cout<<" ";
                qu.push(nullptr);
            }
	    }

	}
}