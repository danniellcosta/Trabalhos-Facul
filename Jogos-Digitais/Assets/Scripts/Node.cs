using System.Collections.Generic;
using UnityEngine;

public class Node : MonoBehaviour
{
    public LayerMask layerParede;
    public List<Vector2> DirecoesDisponiveis { get; private set; }

    private void Start()
    {
        this.DirecoesDisponiveis = new List<Vector2>();
        CheckDirecaoDisponivel(Vector2.up);
        CheckDirecaoDisponivel(Vector2.down);
        CheckDirecaoDisponivel(Vector2.left);
        CheckDirecaoDisponivel(Vector2.right);
    }

    private void CheckDirecaoDisponivel(Vector2 direcao)
    {
        RaycastHit2D hit = Physics2D.BoxCast(this.transform.position, Vector2.one * 0.55f, 0f, direcao, 1.0f, layerParede);

        if (hit.collider == null)
        {
            this.DirecoesDisponiveis.Add(direcao);
        }
    }

}