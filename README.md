# 🔌 Análisis de Redes Eléctricas con el Método de Eliminación de Gauss

## 📋 Descripción del Programa

Este programa en C++ resuelve sistemas de ecuaciones lineales que representan redes eléctricas, utilizando el **método de eliminación de Gauss**. Está diseñado para analizar cómo circula la corriente entre nodos conectados mediante resistencias.

---

## 🧠 ¿Qué hace el programa?

- Solicita al usuario el **número de nodos** de la red eléctrica (entre 2 y 20).
- Para cada nodo, permite:
  - Indicar si hay una corriente directa que entra o sale.
  - Definir cuántas corrientes están conectadas al nodo.
  - Especificar si una corriente va hacia otro nodo o hacia tierra.
  - Introducir el valor de la **resistencia** entre nodos.
- Construye una **matriz de coeficientes** y un **vector independiente** usando las leyes de Kirchhoff.
- Aplica el método de **eliminación de Gauss con pivoteo parcial**.
- Muestra el sistema de ecuaciones y los **valores de corriente en cada nodo**.

---

## 🧮 Funciones principales

### `gauss(...)`
- Controla todo el proceso de resolución.
- Llama a `eliminate` y `substitute` para obtener el resultado final.

### `eliminate(...)`
- Realiza la eliminación hacia adelante de la matriz.
- Utiliza pivoteo parcial para mejorar la estabilidad numérica.

### `pivot(...)`
- Determina la mejor fila para usar como pivote con base en los coeficientes de escala.

### `substitute(...)`
- Realiza sustitución hacia atrás para encontrar las incógnitas.

### `imprimirValores(...)`
- Muestra el sistema de ecuaciones original y la solución final en consola.
- Utiliza letras como `x`, `y`, `z`, etc., para representar cada incógnita.

---

## 💡 Detalles adicionales

- Utiliza matrices de tamaño fijo `20x20`.
- Se guardan copias del sistema (`aCopia` y `bCopia`) para mostrar la representación original.
- Interfaz en consola interactiva.
- Las funciones están separadas para mantener claridad y reutilización del código.
- Incluye control de errores básicos como número mínimo/máximo de nodos.

---

## ✅ Resultado

El programa imprime:
- El sistema de ecuaciones generado con variables.
- El valor de las incógnitas (corrientes en cada nodo).
