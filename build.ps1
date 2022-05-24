
function build_number_library {
    echo "Building Number library..."
    g++ -c Number/Number.cpp -o build/Number.o
    ar rvs build/Number.lib build/Number.o
    echo "Building Number library done"
}

function build_vector_library {
    echo "Building Vector library..."
    g++ -c -INumber Vector/Vector.cpp -o build/Vector.o
    g++ -shared -o build/libVector.dll build/Vector.o build/Number.lib
    echo "Building Vector library done"
}

function build_client_app {
    echo "Building Client App..."
    g++ -INumber -IVector -Lbuild/ -lVector ClientApp/ClientApp.cpp -o build/ClientApp.exe
    echo "Building Client App done"
}

function build {
    if (-Not (Test-Path -Path build)) {
        mkdir build
    }
    build_number_library
    build_vector_library
    build_client_app  
}

function run {   
    echo "Running the Client App"
    .\build\ClientApp.exe
    echo "The Client App is done"
}

function Clean{
    echo "Deleting build files..."
    if (Test-Path -Path build) {
        rm -r build
    }
    echo "Build files deleted"
}

Build
Run
Clean