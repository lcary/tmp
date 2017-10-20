

def get_max_delta(values):
    """
    Maximum delta in list of values going forward
    (max value cannot occur in list before min value)
    """
    mind = {'index': None, 'value': None}
    maxd = {'index': None, 'value': None}
    
    for (index, n) in enumerate(values):
        if mind['value'] is None or n < mind['value']:
            mind['index'] = index
            mind['value'] = n

        if (maxd['value'] is None or n > maxd['value']) and index > mind['index']:
            maxd['index'] = index
            maxd['value'] = n
        
    return maxd['value'] - mind['value']

values = [10, 7, 5, 8, 11, 9]

rv = get_max_delta(values)
# returns 6 (buying for $5 and selling for $11)
print(rv)
