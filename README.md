# 🥥 CocoBash - The Ultimate Custom Shell 🚀

CocoBash is a **versatile, fast, and customizable shell** for Linux, built in C.  
It supports **advanced command execution**, **timeout-based processes**, and **aesthetic terminal prompts** for a superior CLI experience.

---

## 🌟 Features
- ⚡ **Versatile Command Execution** – Run a wide range of commands seamlessly  
- ⏳ **Custom Timeout Execution** – Kill long-running processes automatically  
- 🎨 **Stylish & Colorful Prompt** – Eye-catching, customizable shell appearance  
- 🏗️ **Robust Argument Handling** – Pass arguments directly via terminal  
- 🔄 **Interactive & Non-Interactive Mode** – Execute commands inside the shell or directly from startup  

---

## 📥 Installation & Compilation

### 🔹 Clone the Repository
Run the following commands in your terminal:

```text
git clone https://github.com/yourusername/CocoBash-Shell.git  
cd CocoBash
```

🔹 Compile the Shell
Use the following command to compile CocoBash:

```text
gcc CocoBash.c -o CocoBash
```
🔹 Run the Shell
To start CocoBash, run:

```text
./CocoBash
```  
# 🎯 Usage Examples 
<br>

## 🔹 Run Commands Inside CocoBash
```text
command -option argument
```  
Example:

```text
find . -type f -name "*.c"  
ps aux | grep process_name
```
## 🔹 Execute Commands with a Timeout
```text
timeout 5 some_command
``` 
⏳ This will terminate some_command after 5 seconds.

Example:

```text
timeout 3 sleep 10
```
🕒 This will kill sleep 10 after 3 seconds.

## 🔹 Change Directories
```text
cd /home/user/Documents
```
## 🔹 Run CocoBash with a Command at Startup
You can execute a command directly when starting CocoBash:

```text
./CocoBash echo "Hello, World!"
```

⚙️ How It Works
🛠️ Shell Execution Flow
1️⃣ Displays a Prompt → "Coconut's Shell: /home/user > $"
2️⃣ Waits for User Input → Reads input using fgets().
3️⃣ Parses Command & Arguments → Uses strtok() for tokenization.
4️⃣ Executes Command → Calls fork() and execvp().
5️⃣ Handles Timeout (if specified) → Spawns a timer process.
6️⃣ Supports Argument Passing – Run commands with multiple arguments effortlessly.

⏳ Timeout Handling
CocoBash allows timed execution of commands:

```text
./CocoBash timeout 5 some_command
```
If the command exceeds 5 seconds, it will be forcefully terminated.

🛠️ Dependencies
✅ Linux OS
✅ GCC (GNU Compiler Collection)
📜 License
This project is open-source under the MIT License. Feel free to modify and contribute! 🤖

🤝 Contributing
🔥 Want to improve CocoBash?
Submit issues, feature requests, or pull requests on GitHub.

⭐ Support & Feedback
If you find CocoBash useful, give it a star ⭐ on GitHub!
For feedback or suggestions, open an issue or reach out. 🚀

Author: [Ali Imran]
📂 GitHub Repo: CocoBash-Shell
