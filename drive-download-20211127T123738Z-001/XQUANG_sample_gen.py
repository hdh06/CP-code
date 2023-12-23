import math
import random
import math

RANDOM_SEED = 0 # cần đổi SAMPLE_SEED
oo = 10 ** 9

random.seed(RANDOM_SEED)
seeds = [random.randint(1, 10**9) for i in range(50)]


for s in range(len(seeds)):
    random.seed(seeds[s])

    n = random.randint(10, 100)
    file_ext = "0" * (3-len(str(s))) + str(s)

    points = []
    with open(f"./output.{file_ext}", "w") as f:
        for i in range(n):
            points.append([random.randint(-oo, oo), random.randint(-oo, oo)])
            f.write(f"{points[-1][0]} {points[-1][1]}")

    
    conditions = []
    for i in range(n):
        for j in range(n):
            for k in range(j+1, n):
                if i==j or k==i:
                    continue

                dis_ij = math.hypot(points[j][0] - points[i][0], points[j][1] - points[i][1])
                dis_ik = math.hypot(points[i][0] - points[k][0], points[i][1] - points[k][1])

                if abs(dis_ij - dis_ik) < 0.01:
                    continue

                if dis_ij < dis_ik:
                    conditions.append(f"{i+1} {j+1} {k+1}")
                else:
                    conditions.append(f"{i+1} {k+1} {j+1}")

    with open(f"./input.{file_ext}", "w") as f:
        f.write(f"{n} {len(conditions)}\n")
        f.write("\n".join(conditions)) 

        