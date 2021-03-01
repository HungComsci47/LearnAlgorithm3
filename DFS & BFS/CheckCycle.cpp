cycle = false;

void dfs(int u) {
    visit[u] = 1; // đã được thăm trong quá trình duyệt cây dfs gốc u
    for(int v : a[u])
        if (visit[v] == 0) dfs(v);
        else if (visit[v] == 1) cycle = true; // nếu gặp 1 đỉnh v đã được thăm trong quá trình duyệt cây dfs gốc u, thì đồ thị có chu trình (chu trình này nằm trong cây dfs gốc u)

    visit[u] = 2; // kết thúc quá trình duyệt cây dfs gốc u, tất cả các đỉnh con trong cây này đều được cập nhập visit = 2
}

if (cycle) // đồ thị G có chu trình
