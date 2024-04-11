def load_file(name: str):
    with open(name, 'r') as file:
        file_contents = file.read()
        return file_contents
