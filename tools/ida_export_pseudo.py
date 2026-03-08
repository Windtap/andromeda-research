import idaapi
import idautils
import idc
import os

def export_pseudocode():
    # Проверяем наличие декомпилятора
    if not idaapi.init_hexrays_plugin():
        print("Hex-Rays decompiler is not available.")
        return

    # Путь для сохранения (рядом с файлом базы данных)
    input_file = idaapi.get_input_file_path()
    output_dir = os.path.join(os.path.dirname(input_file), "pseudocode_export")
    
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    print(f"Exporting pseudocode to: {output_dir}")

    for ea in idautils.Functions():
        func_name = idc.get_func_name(ea)
        # Очищаем имя от спецсимволов для файловой системы
        safe_name = "".join([c for c in func_name if c.isalnum() or c in (' ', '.', '_')]).rstrip()
        file_path = os.path.join(output_dir, f"{safe_name}.c")

        try:
            cf = idaapi.decompile(ea)
            if cf:
                with open(file_path, "w") as f:
                    f.write(str(cf))
                print(f"Exported: {func_name}")
            else:
                print(f"Failed to decompile: {func_name}")
        except Exception as e:
            print(f"Error decompiling {func_name}: {str(e)}")

    print("Export finished.")

if __name__ == "__main__":
    export_pseudocode()
