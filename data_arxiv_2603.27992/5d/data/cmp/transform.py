def reformat_data(input_file, output_file):
    # 定义需要提取的长度值
    lengths = [8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384]
    
    # 读取输入文件并正确处理注释行
    with open(input_file, 'r') as f:
        lines = [line.strip() for line in f.readlines() if line.strip()]  # 移除空行
        
    # 找出真正的标题行和数据行
    header_line = None
    data_line = None
    
    for line in lines:
        if line.startswith('#'):
            # 移除开头的#并分割
            stripped = line.lstrip('#').strip()
            if stripped.startswith('D'):
                header_line = stripped
        elif line.strip() and not header_line:
            # 如果遇到非注释行且尚未找到标题行
            header_line = line
        elif line.strip() and header_line and not data_line:
            # 找到标题行后的第一个非注释行作为数据行
            data_line = line
            break  # 找到数据行后停止
    
    if not header_line or not data_line:
        raise ValueError("未找到有效的标题行或数据行")
    
    # 分割标题和数据
    headers = [col.strip() for col in header_line.split('\t') if col.strip()]
    data_values = [val.strip() for val in data_line.split('\t') if val.strip()]
    
    # 确保标题和数据列数匹配
    if len(headers) != len(data_values):
        raise ValueError(f"标题列数({len(headers)})与数据列数({len(data_values)})不匹配")
    
    # 创建标题到数据的映射字典
    data_dict = dict(zip(headers, data_values))
    
    # 准备输出数据
    output_lines = []
    for L in lengths:
        # 获取对应长度的各项数据
        len_val = data_dict.get(f'<Len_{L}>', 'NaN')
        len_err = data_dict.get(f'<Len_{L}>_err', 'NaN')
        lop_val = data_dict.get(f'<Lop_{L}>', 'NaN')
        lop_err = data_dict.get(f'<Lop_{L}>_err', 'NaN')
        lenq_val = data_dict.get(f'<LenQ_{L}>', 'NaN')
        lenq_err = data_dict.get(f'<LenQ_{L}>_err', 'NaN')
        lopq_val = data_dict.get(f'<LopQ_{L}>', 'NaN')
        lopq_err = data_dict.get(f'<LopQ_{L}>_err', 'NaN')
        
        # 构建输出行
        output_line = f"{L}\t{len_val}\t{len_err}\t{lop_val}\t{lop_err}\t{lenq_val}\t{lenq_err}\t{lopq_val}\t{lopq_err}"
        output_lines.append(output_line)
    
    # 写入输出文件
    with open(output_file, 'w') as f:
        f.write('\n'.join(output_lines))

# 使用示例
if __name__ == "__main__":
    sigma_list = ['2.000', '2.500']
    for s_idex in sigma_list:
        input_filename = f'cmp_sigma_{s_idex}.dat'  # 替换为实际输入文件名
        output_filename = f'plot_sigma_{s_idex}.dat'  # 替换为实际输出文件名
        reformat_data(input_filename, output_filename)