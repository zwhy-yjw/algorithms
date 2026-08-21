# C++ 算法学习仓库

记录 C++ 算法基础课的学习过程：刷题代码、思路笔记、套路总结。

## 目录结构

```
algorithms/
├── 分类文件夹/          # 算法分类
├── 单元分类/          # 题型分类
├── 代码.cpp + 题目描述.md/      #一个题目：一份源码 + 一份文档
```

## 单题目录规范

以 `001_two_sum/` 为例：

```
001_two_sum/
├── main.cpp      # 解法代码（可直接提交 OJ 的版本）
├── note.md       # 题目描述
```

命名：`编号_英文名`（如 `023_merge_two_sorted_lists`），编号与刷题顺序对应，方便回溯。

## Git 使用

```bash
git status          # 查看状态
git add .           # 暂存所有改动
git commit -m "做题: 两数之和 (哈希表 O(n))"   # 提交
git push            # 推送到 GitHub
```
