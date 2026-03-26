package com.example.todo_list.ui.components

import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.material3.Button
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.res.stringResource
import com.example.todo_list.R

@Composable
fun ClearButton(
    onClear: () -> Unit,
    modifier: Modifier = Modifier
) {
    Button(
        onClick = onClear,
        modifier = modifier.fillMaxWidth()
    ) {
        Text(text = stringResource(R.string.clear))
    }
}