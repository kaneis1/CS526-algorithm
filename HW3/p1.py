import numpy as np
from scipy.optimize import linprog

# Coefficients matrix A for the inequality constraints
A = np.array([[-3.0, -3/2, -1, -1],
              [-1.0, -2, -4/3, -4/3],
              [-1.0, -1, -5/3, -5/3],
              [-1.0, -1.0, -1.00, -2.00]])

# Right-hand side vector for the inequalities
b = np.array([-1, -1, -1, -1])

# Coefficients for the equality constraint (x1 + x2 + x3 + x4 = 1)
A_eq = np.array([[1, 1, 1, 1]])
b_eq = np.array([1])

# Objective function (set to zero since we are not optimizing any specific function)
c = np.zeros(4)

# Bounds for the variables (0 <= x1, x2, x3, x4 <= 1)
bounds = [(0, 1.000), (0, 1.0000), (0, 1.000), (0, 1.000)]

# Solving the linear programming problem with both inequality, equality constraints, and bounds
result = linprog(c, A_ub=A, b_ub=b, A_eq=A_eq, b_eq=b_eq, bounds=bounds, method='highs')

# Checking if the optimization was successful
if result.success:
    print("Optimal solution found:")
    print(f"x1 = {result.x[0]:.4f}, x2 = {result.x[1]:.4f}, x3 = {result.x[2]:.4f}, x4 = {result.x[3]:.4f}")
else:
    print("No feasible solution found.")
