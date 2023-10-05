Node* merge(Node* left, Node* right) {
    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }

    Node* dummy = new Node(-1);
    Node* temp = dummy;

    while (left != nullptr && right != nullptr) {
        if (left->data < right->data) {
            temp->bottom = left;
            temp = left;
            left = left->bottom;
        } else {
            temp->bottom = right;
            temp = right;
            right = right->bottom;
        }
    }

    while (left != nullptr) {
        temp->bottom = left;
        temp = left;
        left = left->bottom;
    }

    while (right != nullptr) {
        temp->bottom = right;
        temp = right;
        right = right->bottom;
    }

    return dummy->bottom;
}

Node* flatten(Node* root) {
    if (root == nullptr || root->next == nullptr) {
        return root;
    }

    Node* down = root;
    Node* right = flatten(root->next);
    Node* ans = merge(down, right);

    return ans;
}
