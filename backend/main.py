import ctypes

# Define the root directory as the current directory of this file
import os
CDIR = os.path.dirname(os.path.abspath(__file__))

# Load the shared library according to the root directory
quadratic = ctypes.CDLL(CDIR + "/../library/build/libequationSolving.dylib")

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

##############################################################################


from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route('/')
def hello():
    return 'Hello, you ara on the equationSolving backend!'

# curl -X POST -H "Content-Type: application/json" -d '{"a": 1, "b": 2, "c": 1}' http://localhost:5000/quadratic

@app.route('/quadratic', methods=['POST'])
def receive_json():
    try:
        data = request.get_json() # Get the JSON data
        
        if quadratic.validateInputA(data['a']): # check if a is valid
            return jsonify({"error": "Invalid input for 'a'. 'a' must not be zero."}), 400
        else :
            discriminant = quadratic.calculateDiscriminant(data['a'], data['b'], data['c'])
            roots = quadratic.calculateRoots(data['a'], data['b'], data['c'])
            return jsonify({
                "discriminant": discriminant,
                "roots": {
                    "type": roots.type.decode("utf-8"),
                    "root1": {
                        "real": roots.root1.real,
                        "imaginary": roots.root1.imaginary
                    },
                    "root2": {
                        "real": roots.root2.real,
                        "imaginary": roots.root2.imaginary
                    }
                }
            })

    except Exception as e:
        return jsonify({"error": str(e)}), 400  # Return an error response


if __name__ == '__main__':
    # launch the Flask dev server on port 5000
    app.run(host='localhost', port=5000)
