# Що це таке?

Це репозиторій, в якому знаходяться файли простої гри, яку Месники Коваля розроблятимуть,
користуючись бібліотекою Raylib.

# Що необхідно встановити?

Для успішної роботи необхідно встановити CMake, clang-format та будь-який компілятор.

Примітка для встановлення програм
- для Windows, використовуйте [winget](https://github.com/microsoft/winget-cli) (повинно бути одразу в системі). Якщо winget не може бути встановленим, використовуйте [choco](https://chocolatey.org/install).
- для MacOS, використовуйте [brew](https://brew.sh/).
- Якщо виникла якась проблема з CMake, перевірте чи знаходиться він у PATH.

<details>
<summary>Комманди для встановлення</summary>

- Debian/Ubuntu:

		sudo apt-get install cmake clang-format build-essential

- Windows:

		winget install Kitware.CMake LLVM.LLVM
    або
        
        choco install cmake llvm

- MacOS:

		brew install cmake llvm clang-format
</details>


Рекомендований редактор коду — VSCode. При відкритті проєкту у VSCode вам запропнує встановити
рекомендовані розширення, що дуже рекомендується.

# Як цим користуватись?

Після встановлення розширення CMake-Tools знизу звʼявиться панель, де потрібно обрати пресет
"Select a configure preset" (це буде компілятор, що у вас встановлений + Debug/Release) та
натиснути на кнопку Play (⏵). Після цього проєкт запуститься.

