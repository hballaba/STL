//node* minimum(nodeptr x) {
//				if (!x->left)
//					return x;
//				return minimum(x->left);
//			}
//
//
//			nodeptr _delete(nodeptr del, key_type z) {               // корень поддерева, удаляемый ключ
//				if (!del)
//					return del;
//				if (z < del->date.first)
//					del->left = _delete(del->left, z);
//				else if (z > del->date.first)
//					del->right = _delete(del->right, z);
//				else if (del->left && del->right) {
//					del->date.first = minimum(del->right)->date.first;
//					del->right = _delete (del->right, del->date.first);
//				}
//				else {
//					if (del->left)
//						del = del->left;
//					else if (del->right)
//						del = del->right;
//					else
//						del = nullptr;
//				}
//					return del;
//
//			}