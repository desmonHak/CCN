from distutils.core import setup, Extension
from os.path        import join
from os             import listdir

"""
 * python setup.py build_ext --inplace
 * utiliza setup.py para crear nuestros
 * módulos de extensión. El indicador --inplace mueve los objetos compartidos
 * compilados al árbol de origen para que estén en la ruta de búsqueda de Python.
"""

# https://stackoverflow.com/questions/64261546/how-to-solve-error-microsoft-visual-c-14-0-or-greater-is-required-when-inst

# Obtener la lista de archivos en el directorio src con sus rutas completas
src_dir = "src"
src_soruces = [join(src_dir, file) for file in listdir(src_dir) if file.endswith(".c")]
print(src_soruces)

object_dir = "bin"
object_bin = [f"{join('bin','time_code.o')}"]
#[join(object_dir, file) for file in listdir(object_dir) if file.endswith(".o")]
print(object_bin)

def main():
    setup(
        name         = "CCN_lib",
        version      = "1.0.0",
        description  = "Proyect CCN",
        author       = "desmonHak",
        author_email = "",
        packages=["."],  # Incluye el directorio actual
        package_data={
            "": [
                "include/*",
                "src/*",
                "lib/**/*",
                "tools/*",
                "lib/DebugLibC/colors-C-C-plus-plus/*"
            ],  # Incluir archivos y directorios adicionales
        },
        data_files=[
            ("bin", ["bin/time_code.o"]),  # Archivos adicionales en carpetas específicas
            #("doc", ["doc/*"]),   # Documentación
        ],
        
        ext_modules  = [
            Extension(
                "CCN_lib",
                sources=[] + src_soruces ,
                include_dirs=[
                    "include",  # Directorio que contiene los archivos de encabezados
                    "lib/DebugLibC/colors-C-C-plus-plus",  # Agrega todos los directorios necesarios
                ],
                define_macros=[("DEBUG_ENABLE_CCN", None)],  # Definir la macro -DDEBUG_ENABLE_CCN
                extra_link_args = [] + object_bin,
            )
        ],
        classifiers=[
            'Natural Language :: Spanish',
            'Programming Language :: Python :: 3 :: Only',
            'Programming Language :: Python :: Implementation :: CPython',
        ],
        include_package_data=True,  # Asegura que los archivos declarados se incluyan
    )

if __name__ == "__main__":
    main()