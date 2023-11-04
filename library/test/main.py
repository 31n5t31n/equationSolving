import ctypes

# Define the root directory as the current directory
import os
CDIR = os.path.dirname(os.path.abspath(__file__))


# Load the shared library according to the root directory
quadratic = ctypes.CDLL(CDIR + "/../build/libequationSolving.dylib")

# Define the data structures
class Imaginary(ctypes.Structure):
    _fields_ = [("real", ctypes.c_float), ("imaginary", ctypes.c_float)]

class Roots(ctypes.Structure):
    _fields_ = [("root1", Imaginary), ("root2", Imaginary), ("type", ctypes.c_char * 32)]

# Define the function prototypes
quadratic.validateInputA.argtypes = [ctypes.c_float]
quadratic.validateInputA.restype = ctypes.c_int

quadratic.calculateDiscriminant.argtypes = [ctypes.c_float, ctypes.c_float, ctypes.c_float]
quadratic.calculateDiscriminant.restype = ctypes.c_float

quadratic.calculateRoots.argtypes = [ctypes.c_float, ctypes.c_float, ctypes.c_float]
quadratic.calculateRoots.restype = Roots

# Now, you can use the C library functions in Python
a = 7
b = 3
c = 10

# Call the functions
valid_a = quadratic.validateInputA(a)
discriminant = quadratic.calculateDiscriminant(a, b, c)
roots = quadratic.calculateRoots(a, b, c)

if valid_a == 0:
    print(f"Discriminant: {discriminant}")
    print(f"Root 1: Real={roots.root1.real}, Imaginary={roots.root1.imaginary}")
    print(f"Root 2: Real={roots.root2.real}, Imaginary={roots.root2.imaginary}")
    print(f"Type: {roots.type}")
else:
    print("Invalid input for 'a'. 'a' must not be zero.")
