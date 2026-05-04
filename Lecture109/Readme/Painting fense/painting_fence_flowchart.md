## 📊 Flowchart Visualization

```text
                Start
                  │
                  ▼
        ┌───────────────────┐
        │   Initialize      │
        │ dp[1] = K         │
        │ dp[2] = K * K     │
        └───────────────────┘
                  │
                  ▼
        ┌───────────────────┐
        │   For i = 3 → N   │
        └───────────────────┘
                  │
                  ▼
        ┌──────────────────────────────┐
        │ SAME = diff[i-1]             │
        │ (only if previous were diff) │
        └──────────────────────────────┘
                  │
                  ▼
        ┌──────────────────────────────┐
        │ DIFF = (same + diff) * (K-1) │
        │ (choose different color)     │
        └──────────────────────────────┘
                  │
                  ▼
        ┌───────────────────┐
        │ dp[i] = SAME + DIFF │
        └───────────────────┘
                  │
                  ▼
        ┌───────────────────┐
        │   Repeat loop     │
        └───────────────────┘
                  │
                  ▼
        ┌───────────────────┐
        │   Return dp[N]    │
        └───────────────────┘
```

---

## 🎬 Interviewer-Style Thinking (Step-by-Step)

> 💬 *“Let’s not jump to formula. Let’s think like a problem solver.”*

---

### 🧩 Step 1: Understand Constraint

```text
No more than 2 adjacent same colors
→ Means 3 same in a row is NOT allowed ❌
```

---

### 🧩 Step 2: Think Local (At Current Post)

Ask:

```text
What matters for current post?
→ Only previous 1 or 2 posts
```

So we define:

* SAME → last two same
* DIFF → last two different

---

### 🧩 Step 3: Try to Build for Next Post

#### 👉 Case 1: Make current SAME

```text
Can we do this always? ❌

Example:
AAA → not allowed

So SAME is only possible if previous were DIFF
```

✅ Conclusion:

```text
same = diff (previous)
```

---

#### 👉 Case 2: Make current DIFFERENT

```text
Can we always choose a different color? ✅ YES

How many choices?
→ Total colors = K
→ Remove previous color = 1

Valid choices = K - 1
```

✅ Conclusion:

```text
diff = (same + diff) * (K - 1)
```

---

### 🧩 Step 4: Combine

```text
Total ways = same + diff
```

---

### 🧩 Step 5: Convert to DP Formula

```text
dp[i] = (dp[i-1] + dp[i-2]) * (K - 1)
```

---

## 🧠 Mental Model (Interviewer Trick)

```text
At every step:

Do I continue a pair? → SAME
Do I break the chain? → DIFF

And for DIFF:
→ I always have (K - 1) safe choices
```

---

## ⚡ One-Line Insight

```text
We are not counting colors,
we are counting VALID choices at each step.
```

---

<p align="center">
  🚀 <b>This is how you explain DP in interviews.</b>
</p>
