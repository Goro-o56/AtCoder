import os
import subprocess
import time

# 指定ディレクトリ
directory = "./15"

# cppファイルの一覧を取得
cpp_files = [f for f in os.listdir(directory) if f.endswith(".cpp")]

# 以前の最終更新日時を保存する辞書
last_modified_time = {}

while True:
    # 差分があるかどうかを判定
    for cpp_file in cpp_files:
        # cppファイルの最終更新日時を取得
        current_modified_time = os.stat(os.path.join(directory, cpp_file)).st_mtime
        # 以前の最終更新日時と比較
        if cpp_file not in last_modified_time or last_modified_time[cpp_file] != current_modified_time:
            # 差分がある場合はg++でコンパイルし、oj tを実行
            subprocess.run(["g++", cpp_file, "-o", cpp_file.replace(".cpp", ".out")], cwd=directory)
            subprocess.run(["oj", "t", cpp_file.replace(".cpp", ".out")], cwd=directory)
            # 最終更新日時を更新
            last_modified_time[cpp_file] = current_modified_time

    # 一定間隔で監視を続ける
    time.sleep(10)