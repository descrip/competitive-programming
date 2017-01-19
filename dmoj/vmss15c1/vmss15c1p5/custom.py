from judge import CheckerResult

def check(process_output, judge_output, judge_input, point_value, submission_source, **kwargs):
    process_lines = filter(None, process_output.split('\n'))
    process_data = filter(None, process_output.split())
    judge_data = filter(None, judge_output.split())
    input_data = filter(None, judge_input.split())

    #Problem variables.
    N,R,S = input_data[0:3]
    apples = []
    for i in range(3,input_data.size(),3):
        apples.append((int(input_data[i+1]),int(input_data[i+2]),int(input_data[i+3])))
    tot_val,tot_cost,tot_vol = 0

    if not process_lines:
        return CheckerResult(False, 0)
    if len(process_lines) > N+1:
        return CheckerResult(False, 0, 'Too many lines of output.')
    if any(len(process_lines[i]) > 65536 for i in xrange(len(process_lines))):
        return CheckerResult(False, 0, 'Output limit exceeded.')
    
    if process_data[0] != judge_data[0]:
        return CheckerResult(False, 0, 'Maximum value incorrect.')

    try:
        apple_num = 0
        for i in xrange(1,2*N+1,2):
            number = int(process_data[i+1])
            tot_val += apples[apple_num][0] * number
            tot_cost += apples[apple_num][1] * number
            tot_vol += apples[apple_num][2] * number
            apple_num += 1
    except:
        return CheckerResult(False, 0, 'Output form incorrect.')

    if tot_val == judge_data[0] and tot_cost <= R and tot_vol <= S:
        return CheckerResult(True, point_value, 'Correct answer.')
    else:
        return CheckerResult(False, 0, 'Maximum value correct, but apple quantities do not fit limits.')
