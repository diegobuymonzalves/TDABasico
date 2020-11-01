#include <iostream>
#include <string>
#include <vector>
#include <fcntl.h>
#include <io.h>
#include <exception>

/**
* Estructura de dato: Student.
* Mantiene información de un estudiante.
*/
class Student {
public:
    void setNombre(const std::wstring &nombre) {this->nombre = nombre;}
    const std::wstring &getNombre() const {return this->nombre;}

    void setApellidoP(const std::wstring &apellidoPaterno) {
        this->apellidoPaterno = apellidoPaterno;
    }
    const std::wstring &getApellidoP() const {return this->apellidoPaterno;}

    void setApellidoM(const std::wstring &apellidoMaterno) {
        this->apellidoMaterno = apellidoMaterno;
    }
    const std::wstring &getApellidoM() const {return this->apellidoMaterno;}

    void setCorreo(const std::wstring &correo) {this->correo = correo;}
    const std::wstring &getCorreo() const {return this->correo;}

    void setTelefono(const std::wstring &telefono) {this->telefono = telefono;}
    const std::wstring &getTelefono() const {return this->telefono;}

    void setNoControl(const std::wstring &noControl) {this->noControl = noControl;}
    const std::wstring &getNoControl() const {return this->noControl;}

    void setEdad(unsigned long edad) {this->edad = edad;}
    unsigned long getEdad() const {return this->edad;}

private:
    std::wstring nombre;
    std::wstring apellidoPaterno;
    std::wstring apellidoMaterno;
    std::wstring correo;
    std::wstring telefono;
    std::wstring noControl;
    unsigned long edad;
};

void printStudents(const std::vector<Student> &students);

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    std::wcout << L"Ingresar información de los alumnos:" << std::endl;
    std::wcout << L"Para finalizar escribe \"fin\"." << std::endl;
    std::wstring dataIn;

    std::vector<Student> students;
    Student student;
    unsigned counter = 1;
    bool stateEdad = false;
    unsigned long edad;

    while(true) {
        std::wcout << L"\nAlumno " << counter << std::endl;
        std::wcout << L"Nombre)> ";
        std::getline(std::wcin, dataIn);

        if(dataIn == L"fin")
            break;

        student.setNombre(dataIn);
        std::getline(std::wcin, dataIn);

        std::wcout << L"Apellido Paterno)> ";
        std::getline(std::wcin, dataIn);
        student.setApellidoP(dataIn);
        std::getline(std::wcin, dataIn);

        std::wcout << L"Apellido Materno)> ";
        std::getline(std::wcin, dataIn);
        student.setApellidoM(dataIn);
        std::getline(std::wcin, dataIn);

        std::wcout << L"Número de control)> ";
        std::getline(std::wcin, dataIn);
        student.setNoControl(dataIn);
        std::getline(std::wcin, dataIn);

        std::wcout << L"Apellido Correo)> ";
        std::getline(std::wcin, dataIn);
        student.setCorreo(dataIn);
        std::getline(std::wcin, dataIn);

        while(!stateEdad) {
            std::wcout << L"Edad)> ";
            std::getline(std::wcin, dataIn);
            try {
                edad = std::stoul(dataIn);
                student.setEdad(edad);
                stateEdad = true;
            } catch(std::invalid_argument &exp) {
                std::wcout << L"\"" << dataIn << L"\" no es un valor valido para edad. Ingrese un valor valido" << std::endl;
            } catch(std::out_of_range &exp) {
                std::wcout << L"\"" << dataIn << L"\" es demasiado grande para ser almacenado" << std::endl;
            }
            std::getline(std::wcin, dataIn);
        }
        stateEdad = false;

        std::wcout << L"Número de télefono)> ";
        std::getline(std::wcin, dataIn);
        student.setTelefono(dataIn);
        std::getline(std::wcin, dataIn);

        students.push_back(student);
        counter++;
    }

    if(students.empty()) {
        std::wcout << L"No se ingresaron datos" << std::endl;
    }

    std::wcout << L"\nSe ingreso información de los siguientes estudiantes:" << std::endl;
    printStudents(students);
    return 0;
}

void printStudents(const std::vector<Student> &students) {
    for(const Student student: students) {
        std::wcout << student.getNombre() << L" " << student.getApellidoP()
            << L" " << student.getApellidoM() << std::endl;
        std::wcout << L"Número de control: " << student.getNoControl() << std::endl;
        std::wcout << L"Correo: " << student.getCorreo() << std::endl;
        std::wcout << L"Edad: " << student.getEdad() << std::endl;
        std::wcout << L"Numéro de teléfono: " << student.getTelefono() << L"\n"<< std::endl;
    }
}
