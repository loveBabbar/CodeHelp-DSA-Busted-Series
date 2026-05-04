## 🎥 Dry Run Visualization

Let’s understand the DP flow with a visual example.

---

### 🧪 Example

```text
N = 3, K = 2
Colors = {0, 1}
```

---

## 🪵 Step 1: First Post

```text
Post 1:
[ _ ]

Choices → {0, 1}
Total ways = 2
```

---

## 🪵 Step 2: Second Post

```text
Post 1 → Post 2

[ 0 ] → [ 0 ]   (same)
[ 0 ] → [ 1 ]   (diff)
[ 1 ] → [ 1 ]   (same)
[ 1 ] → [ 0 ]   (diff)

Total = 4
```

🧠 Breakdown:

* same = 2 → (00, 11)
* diff = 2 → (01, 10)

---

## 🪵 Step 3: Third Post

Now apply DP logic:

---

### 🔁 SAME case

We can only make current post same if previous were **different**

```text
From diff:
01 → 011
10 → 100

same = 2
```

---

### 🔄 DIFF case

Pick a different color than previous:

```text
From all previous:

00 → 001
11 → 110
01 → 010
10 → 101

diff = 4
```

---

## 📊 Final Count

```text
Total = same + diff
      = 2 + 4
      = 6 ✅
```

---

## 🎯 Valid Combinations

```text
110
001
101
100
010
011
```

---

## 🧠 Visual DP Flow

```text
dp[1] = 2
        ↓
dp[2] = 4
        ↓
dp[3] = (dp[2] + dp[1]) * (K - 1)
      = (4 + 2) * 1
      = 6
```

---

## 🔥 Key Insight (Visual Form)

```text
         Previous
        /        \
    SAME        DIFF
     ❌           ✅ → SAME allowed
                  \
                   → choose (K-1) colors → DIFF
```

---

## 💡 Intuition Snapshot

* SAME only comes from DIFF
* DIFF comes from ALL previous × (K - 1)
* `(K - 1)` = exclude previous color

---

<p align="center">
  🎯 <b>Think in transitions, not brute force.</b>
</p>
