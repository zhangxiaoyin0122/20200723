#include <iostream>
using namespace std;

class Solution {
public:
	stack<int> data_st;
	stack<int> min_st;

	void push(int value) {
		if (min_st.empty() || value < min_st.top()) {
			min_st.push(value);
		}
		else {
			min_st.push(min_st.top());
		}
		data_st.push(value);
	}
	void pop() {
		data_st.pop();
		min_st.pop();
	}
	int top() {
		return data_st.top();
	}
	int min() {
		return min_st.top();
	}
};


class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.empty() || popV.empty() || pushV.size() != popV.size())
			return false;
		stack<int> st; //����ջ,ģ����ջ��ջ
		int j = 0;
		for (int i = 0; i < pushV.size(); i++) {
			st.push(pushV[i]);
			while (!st.empty() && st.top() == popV[j]) {
				st.pop();
				j++;
			}
		}
		return st.empty();
	}
};

class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> result;
		if (root == nullptr) //���ǵ����������
			return result;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) { //����ѭ������:������Ϊ��ʱ
			TreeNode* p = q.front();
			q.pop();
			result.push_back(p->val);
			if (p->left) {
				q.push(p->left);
			}
			if (p->right) {
				q.push(p->right);
			}
		}
		return result;
	}
};
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == nullptr || pHead->next == nullptr)
			return pHead;
		ListNode* newHead = new ListNode(0); //ͷ���
		newHead->next = pHead;
		ListNode* prev = newHead;
		ListNode* last = prev->next;
		while (last) {
			while (last->next && last->val != last->next->val) {
				prev = last;
				last = last->next;
			}
			while (last->next && last->val == last->next->val) {
				last = last->next;
			}
			if (prev->next != last) {
				prev->next = last->next;
			}
			last = last->next;
		}
		return newHead->next;
	}
};