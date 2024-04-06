README
Integrantes:
Sebastián Vega Chepillo; 21.349.057-5; sebastian.vega03@alumnos.ucn.cl
Maximiliano Alfredo Pasten Nayem; 20.169.262-8; maximiliano.pasten@alumnos.ucn.cl
 
Organizador de Eventos
Información sobre los Objetos
 
Durante el inicio del programa, se crean los siguientes objetos que están presentes en los archivos Personas y Eventos (ambos .txt):
Personas.txt:
{nombre: "Juan", password: "hola123", rut: "11.111.111-1", edad: 42, tipo: "admin", ocupacion: "sin ocupacion", eventoAsignado: "Ninguno"}
{nombre: "Pedro", password: "hola1234", rut: "22.222.222-2", edad: 32,tipo: "visitante", ocupacion: "visitante", eventoAsignado: "Boda de Diego"}
{nombre: "Diego",password: "hola12345", rut: "33.333.333-3", edad: 18, tipo: "trabajador", ocupacion: "decorador", eventoAsignado: "Premiacion de Pedro"}
{nombre: "Pikachu", password: "hola", rut: "12.345.678-9", edad: 18, tipo: "visitante", ocupacion: "visitante",eventoAsignado: "ninguno"}


Eventos.txt:
{nombre: "Boda de Diego", tipo: "boda", fecha: "01-01-2023", tema: "No presenta", ubicacion: "Santiago"},
{nombre": "Premiacion de Pedro", tipo: "premiacion", fecha: "05-02-2024", tema: "No presenta", ubicacion: "La Serena"}
{nombre: "Fiesta de Maria", tipo: "fiesta", fecha: "02-02-2024", tema: "Disfraces", ubicacion: "Coquimbo"}

Contenido de los Archivos
 
-main.cpp: Contiene el programa principal que controla la lógica del sistema y las funciones que se usarán en a la hora de ejecutar el código.
-Persona.cpp: Implementa la clase Persona que representa a los individuos que asisten a los eventos.
-Persona.h: Define la clase Persona y sus métodos.
-Evento.cpp: Implementa la clase Evento que representa los eventos organizados.
-Evento.h: Define la clase Evento y sus métodos.
-personas.txt: Archivo de texto que contiene la información de las personas.
-eventos.txt: Archivo de texto que contiene la información de los eventos.
 
Instrucciones para Compilar y Ejecutar
Para compilar y ejecutar el programa, sigue estos pasos:
 
1. Abre la terminal en el directorio del proyecto.
2. Compila el programa utilizando el siguiente comando:
g++ main.cpp Persona.cpp Evento.cpp -o main
3. Ejecuta el programa con el siguiente comando:
./main 
Instrucciones de Uso
1. Ejecuta el programa.
2. Se mostrará un menú de opciones, donde se podrá acceder al menú de administrador ingresando la opción correspondiente y con las credenciales correctas.
3. Desde el menú de administrador, puedes:
   - Crear un nuevo evento.
   - Registrar asistentes a un evento.
   - Consultar la lista de asistentes a un evento.
   - Generar informes sobre los eventos.
4. Sigue las instrucciones proporcionadas por el programa para realizar las diferentes acciones y los resultados se guardarán en el .txt.
 

Datos de Ejemplo
 
Contenido de personas.txt
 
Juan,hola123,11.111.111-1,42,admin,sin ocupacion,Ninguno
Pedro,hola1234,22.222.222-2,32,visitante,visitante,Boda de Diego
Diego,hola12345,33.333.333-3,18,trabajador,decorador,Premiacion de Pedro
Pikachu,hola,12.345.678-9,18,visitante,visitante,ninguno
 
Contenido de eventos.txt
Boda de Diego,boda,01-01-2023,No presenta,Santiago
Premiacion de Pedro,premiacion,05-02-2024,No presenta,La Serena
Fiesta de Maria,fiesta,02-02-2024,Disfraces,Coquimbo

