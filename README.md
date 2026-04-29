# Codeforces 刷题记录

这个仓库用于记录个人 Codeforces 练习代码，当前主要使用 C++ 编写。

## 目录结构

```text
.
├── README.md
└── acmtrain/
    ├── 2203C.cpp
    ├── 2203D.cpp
    ├── 2203C        # 本地编译产物
    └── 2230D        # 本地编译产物
```

约定：

- `acmtrain/`：存放 Codeforces 题解源码。
- `题号 + 题目字母.cpp`：例如 `2203C.cpp`、`2203D.cpp`。
- 无扩展名文件通常是本地编译生成的可执行文件，不是题解源码。

## 编译与运行

单个文件编译：

```bash
g++ x.cpp  -o x
```

运行：

```bash
./x
```

也可以使用输入文件测试：

```bash
./acmtrain/2203C < input.txt
```

## 当前记录

| 题目 | 源码 | 状态 | 备注 |
| --- | --- | --- | --- |
| Codeforces 2203C | `acmtrain/2203C.cpp` | 已完成 | C++ |
| Codeforces 2203D | `acmtrain/2203D.cpp` | 已完成 | C++ |

## 代码模板

常用 C++ 竞赛模板：

```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define endl '\n'
const int inf = 1000000000000000010LL;

void solve() {
    // solution
}

signed main() {
    IOS;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
```

## 维护建议

- 新增题目时优先提交 `.cpp` 源码，避免提交本地编译产物。
- 如果一道题有多种写法，可以使用 `题号字母_方法.cpp` 命名，例如 `2203C_binary_search.cpp`。
- 提交前建议至少使用样例和自造边界数据测试一次。
- 可以后续补充题目链接、标签、难度和题解思路，方便复盘。
